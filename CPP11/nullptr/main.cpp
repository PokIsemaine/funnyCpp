#include <cstddef>
#include <iostream>
#include <type_traits>

void foo(char *);
void foo(int);

int main() {
	if(std::is_same<decltype(NULL), decltype(0)>::value)
		std::cout << "NULL == 0" << std::endl;
	if(std::is_same<decltype(NULL), decltype((void*)0)>::value)
		std::cout << "NULL == (void*)0" << std::endl;
	if(std::is_same<decltype(NULL), decltype(nullptr)>::value)
		std::cout << "NULL == nullptr" << std::endl;

	foo(0);
	// foo(NULL);	不能编译，C++ NULL 定义为 0,这样会因为重载，导致不知道选哪个函数
	foo(nullptr);

	return 0;
}

void foo(char *) {
	std::cout << "foo(char*0) is called" << std::endl;
}

void foo(int i) {
	std::cout << "foo(int) is called" << std::endl;
}
