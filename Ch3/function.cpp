#include <iostream>
#include <functional>

using foo = void(int);	//定义函数类型

int foo2(int para) {
	return para;
}

void functional(foo f) { //定义在参数列表的函数类型 foo 被是为退化后的函数指针类型 foo*
	f(1);	//通过函数指针调用函数
}

int main() {
	auto f = [](int value) {
		std::cout << value << std::endl;
	};

	// before C++11
	
	functional(f);	// 传递闭包对象，隐式转换为 foo* 类型的函数指针值
	f(1);	// lambda 表达式调用

	// after C++11
	// 统一了这些概念，将能够被调用的对象的类型， 统一称之为可调用类型
	// std::function  是一种通用的、多态的函数封装
	// 可以当制作函数的容易，可以方便的将函数、函数指针作为对象处理
	std::function<int(int)> func = foo2;
	
	int important = 10;
	std::function<int(int)> func2 = [&](int value) -> int {
		return 1+value+important;
	};

	std::cout << func(10) << std::endl;
	std::cout << func2(10) << std::endl;


	return 0;
}
