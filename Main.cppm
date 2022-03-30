import Module;

import <iostream>;

int main()
{
	HelloWorld();

	HelloWorldClass classobj;
	classobj.value = 2;

	HelloWorldStruct structobj;
	structobj.value = 4;

	HelloWorldNamespace::PrintValues(structobj, classobj);

	return 0;
}