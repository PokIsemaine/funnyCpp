#include <functional>
#include <iostream>
#include <string>

using namespace std;

void hello1() {
	cout << "hello world!" << endl;
}

void hello2(string str) {
	cout << str << endl;
}

int sum (int a,int b) {
	return a + b;
}

class Test {
public:
	// 成员方法调用必须依赖一个对象
	// 成员方法会隐含一个 this 指针
	void hello(string str) { cout << str << endl;}
};
int main() {
	/*
		1. 用函数类型实例化 function
		2. 通过 function 调用 operator 的时候要根据函数类型传入参数
	*/


	// 全局函数

	function<void()> func1 = hello1;
	func1();	// func1.operator() => hello1()

	function<void(string)> func2 = hello2;
	func2("hello hello2!");

	function<int(int,int)> func3 = sum;
	cout << sum (1, 3) << endl;


	// lambda 表达式
	function<int(int,int)> func4 = [](int a, int b) -> int { return a + b; };
	cout << func4(10,20) << endl;

	// 类成员函数
	function<void(Test*, string)> func5 = &Test::hello;
	Test* test = new Test;
	func5(test, "call Test::hello!");
	delete test;


	return 0;
}