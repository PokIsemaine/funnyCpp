#include<iostream>
using namespace std;

//before C++17
//enable_if_t C++14 特性
template<typename T>
std::enable_if_t<std::is_integral<T>::value, int> print_type_info(const T& t) {
	return t + 1;
}

template<typename T>
std::enable_if_t<!std::is_integral<T>::value, double>  print_type_info(const T& t) {
	return t + 0.001;
}

//after C++17
//提高了可读性
template<typename T>
auto print_type_info_constexpr(const T& t) {
	if constexpr(std::is_integral<T>::value) {	//不加 constexpr 的话会编译报错的
		return t + 1;
	} else {
		return t + 0.001;
	}
}

int main() {
	std::cout << print_type_info(5) << std::endl;
	std::cout << print_type_info(3.5) << std::endl;

	std::cout << print_type_info_constexpr(6) << std::endl;
	std::cout << print_type_info_constexpr(4.5) << std::endl;
	return 0;
}