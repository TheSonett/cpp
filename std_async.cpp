#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future> // for std::asynce
#include <string>
#include <mutex>

std::mutex m;
struct Structure {
    void foo(int i, const std::string& str) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << str << ' ' << i << '\n';
    }
    void bar(const std::string& str) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << str << '\n';
    }
    int operator()(int i) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << i << '\n';
        return i + 10;
    }
};

template <typename T>
int parallel_sum(T beg, T end)
{
    auto len = end - beg;
    if (len < 1000)
        return std::accumulate(beg, end, 0);

    T mid = beg + len / 2;
    auto handle = std::async(std::launch::async, parallel_sum<T>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}

int main()
{
    std::vector<int> v(10000, 1);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';

    Structure x;

    // Calls (&x)->foo(42, "Hello") with default policy:
    // may print "Hello 42" concurrently or defer execution
    auto a1 = std::async(&Structure::foo, &x, 42, "Hello");

    // Calls x.bar("world!") with deferred policy
    // prints "world!" when a2.get() or a2.wait() is called
    auto a2 = std::async(std::launch::deferred, &Structure::bar, x, "world!");


    // Calls X()(43); with async policy
    // prints "43" concurrently
    auto a3 = std::async(std::launch::async, Structure(), 43);


    a2.wait(); // prints "world!"

    std::cout << a3.get() << '\n'; // prints "53"

} // if a1 is not done at this point, destructor of a1 prints "Hello 42" here



/* Note:
* 
* The function template async runs the function f asynchronously (potentially in a separate thread which might be a part of a thread pool) 
    and returns a std::future that will eventually hold the result of that function call.
* 
* 
* 
* 
* 
* 
*/