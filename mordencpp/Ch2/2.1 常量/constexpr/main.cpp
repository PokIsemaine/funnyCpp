#include <iostream>
#define LEN 10

int len_foo() {
	int i = 2;
	return i;
}

constexpr int len_foo_constexpr() {
	return 5;
}

// CPP14 constexpr 函数内可以使用局部变量和分支，不过clang++ cpp11 貌似也不报错
constexpr int fibnacci_14(const int n) {
	if(n == 1) return 1;
	if(n == 2) return 2;
	return fibnacci(n-1) + fibnacci(n-2);
}
constexpr int fibnacci(const int n) {
	return n == 1 || n == 2 ? 
		1 : fibnacci(n-1) + fibnacci(n-2);	
}

int main() {
	char arr_1[10];
	char arr_2[LEN];
	
	int len = 10;
	//char arr_3[len];

	const int len_2 = len + 1;
	constexpr int len_2_constexpr = 1 + 2 + 3;

	//char arr_4[len_2];
	char arr_4[len_2_constexpr];

	//char arr_5[len_foo() + 5];
	char arr_6[len_foo_constexpr() + 1];

	std::cout << fibnacci(10) << std::endl;
	std::cout << fibnacci_14(10) << std::endl;
	return 0;
}
