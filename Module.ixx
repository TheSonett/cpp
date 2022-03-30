export module Module;

import <iostream>;

export struct HelloWorldStruct {
	int value;
};

export class HelloWorldClass {
public:
	int value;
};

export namespace HelloWorldNamespace {

	void PrintValues(HelloWorldStruct& objS, HelloWorldClass& objC) {
		std::cout << objS.value << " , " << objC.value;
	}
}

void Something() {
	std::cout << "Private Module Function" << std::endl;
}

export void HelloWorld() {
	std::cout << "Public Module Function" << std::endl;
	Something();
}