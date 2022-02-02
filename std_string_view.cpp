#include <iostream>
#include <string>

static uint32_t s_Allcation = 0;

// new operator overloading to track the memory allocation
void* operator new(size_t size) {

	s_Allcation++;
	std::cout << "Allocation " << size << " bytes\n";
	return malloc(size);
}


// Turn ON & OFF string_view
#define STRING_VIEW 1


#if STRING_VIEW
void PrintName(const std::string& name) {
	std::cout << name << std::endl;
}

#else
void PrintName(std::string_view name) {
	std::cout << name << std::endl;
}

#endif


int main()
{
#if STRING_VIEW
	std::string name = "Sonett Saha"; // static string

	std::string firstname = name.substr(0, 6);
	std::string lastname = name.substr(7, 10);

	PrintName(firstname);
	PrintName(lastname);
	PrintName("Sonett Saha");
	// 4 allocations & size is 16 bytes
#else
	std::string_view name("Sonett Saha"); // or const char* name = "Sonett Saha";
	std::string_view firstname(name.substr(0, 6));
	std::string_view lastname(name.substr(7, 10));

	PrintName(firstname);
	PrintName(lastname);
	PrintName("Sonett Saha");
	// O allocations & size is 0 bytes
#endif
	std::cout << s_Allcation << " allocations\n";
	std::cin.get();
}


/* My Notes:
* 
* 1. If we make create string variables using std::string, then it'll allocate memory which is not ideal at all.
* Here in this example, it will allocate 16 bytes for one single std::string.
* 
* 2. We can improve that & can have ZERO allocation for every string. So, How? = by using std::string_view in C++ 17
* std::string_view is string class which is just a pointer to existing memory + a size. It returns a pointer.
* We are not creating a whole new string for that existing string, we want just a window/view at existing string
*/

/* Difference between == & compare() function is C++
* 
* we can compare two strings using compare() function and the == operator. 
	Then the question is why there are two different methods? Is there any difference or not?
* 
*  == operator is overloaded for the string to check whether both strings are same or not. 
	If they are the same this will return 1, otherwise 0. So it is like Boolean type function.
*  
* The compare() function returns two different things. If both are equal, it will return 0, 
  If the mismatch is found for character s and t, and when s is less than t, then it returns -1
  otherwise when s is larger than t then it returns +1. It checks the matching using the ASCII code.

*/