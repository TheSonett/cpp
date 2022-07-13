#include <iostream>
#include <list>

static std::list<int> linkedlist;

void printList() {
	for (auto i = linkedlist.begin(); i != linkedlist.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

void removeElement(int val) {
	linkedlist.remove(val);
}

int main()
{
	linkedlist.push_back(2);
	linkedlist.push_back(3);
	linkedlist.push_back(4);
	linkedlist.push_back(5);
	linkedlist.push_back(6);

	printList();
	removeElement(4);
	printList();

	std::cin.get();
}