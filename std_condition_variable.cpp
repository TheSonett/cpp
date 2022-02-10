/*
* Condition variables can be used for two purposes:
        a. Notify other threads
        b. Wait for some condition
* 
* 
*   1. Condition variables allows running thread to wait on some conditions and once those conditions are met the waiting thread is notidied using:
       a. notify_one();
       b. notify_all();

   2. You need mutex to use condition variable.
   3. If some thread want to wait on some condition then it has to do these things:
            a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(mutex);
            b. Execute wait, wait_for, or wait_until. The wait operations atomatically release the mutex and suspend the execution of the thread.
            c. When the condition variable is notified, the thread is awakened, and the mutex is automatically reacquired.
                The thread should then check the condition and resume waiting if the wake up was spurious.

   NOTE:
       3. Condition variable is used to synchronize two or more threads.
       4. Best use case of condition variable is Producer/Consumer problem. 
*/


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mutex;
std::condition_variable cv;


static int balance = 0;


void withDrawMoney(int money)
{
    std::unique_lock<std::mutex> lock(mutex); // locking the mutex
    cv.wait(lock, []() {                        // It will awake & try to lock the mutex. If so, then the condition is true, so it will go furthur
         return (balance != 0) ? true : false;
    });

    if (balance >= money) {
        balance -= money;
        std::cout << "Amount deducted!" << std::endl;
    }
    else {
        std::cout << "Amount cannot be deducted!" << std::endl;
    }

    std::cout << "Current balance is: " << balance << std::endl;
}


void addMoney(int money)
{
    std::lock_guard<std::mutex> lock(mutex); // releasing mutex & start exectuing this thread as balance is zero
    balance += money; // adding balance
    std::cout << "Money added successfully!" << std::endl;

    cv.notify_one(); // tell that thread who is waiting for this conditional variable means wake that thread
}

int main()
{
    std::thread t1(withDrawMoney, 1000);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread t2(addMoney, 500);

    t1.join();
    t2.join();

    std::cin.get();
}