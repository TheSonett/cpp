// Program to print inorder predecessor and inorder successor

#include <iostream>
#include <set>

static std::set<int> set;

void checkPredecessor(int val) {
	// check if value is present in the set, if not simpily return
	if (set.find(val) == set.end()) {
		std::cout << "Value is not present\n";
		return;
	}

	// check if it is the first element, then it doesn't have predecessor
	if (set.find(val) == set.begin()) {
		std::cout <<  val << " has No Predecessor!\n";
		return;
	}

	// get the previous value
	std::set<int>::iterator it = set.find(val);
	it--;
	std::cout << "The predecessor of " << val << " is: " << *it << "\n";
}

void checkSuccessor(int val) {
	// check if value is present in the set, if not simpily return
	if (set.find(val) == set.end()) {
		std::cout << "Value is not present\n";
		return;
	}

	// get the next value
	std::set<int>::iterator it = set.find(val);
	it++;

	// check if it is the last element, then it doesn't have successor
	if (it == set.end()) {
		std::cout << val << " has No Successor!\n";
		return;
	}
	else {
		std::cout << "The successor of " << val << " is: " << *it << "\n";
	}
}


int main()
{
	set.insert(2);
	set.insert(5);
	set.insert(10);
	set.insert(1);
	set.insert(7);

	for (auto i : set) {
		std::cout << i << " ";
	}printf("\n");


	checkPredecessor(10);
	checkPredecessor(1);
	checkPredecessor(5);

	printf("\n\n");

	checkSuccessor(10);
	checkSuccessor(1);
	checkSuccessor(2);

	std::cin.get();
}