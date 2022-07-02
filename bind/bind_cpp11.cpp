#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

using namespace placeholders;
/*
	C++11 bind 绑定器 返回结果还是一个函数对象
*/

void hello(string str) { cout << str << endl;}

int sum(int a, int b) { return a + b;}

class Test {
public:
	int sum(int a,int b) {return a + b;}
};

int main() {
	// bind 是函数模板 可以自动推演模板类型函数

	bind(hello, "hello bind！") ();

	cout << bind(sum, 10, 20) ()<< endl;

	cout << bind(&Test::sum, Test(), 20 , 30) () << endl;

	// 参数占位符，最多 20 个
	bind(hello, placeholders::_1) ("hello bind 2!");
	cout << bind(sum , _1, _2) (3, 5) << endl;;

	// 绑定器出了语句无法继续使用
	// 使用 function 把 bind 返回的绑定器留下来复用
	function<void(string)> func1 = bind(hello, _1);
	func1("hello china");
	func1("hello zhejiang");
	func1("hello harbin");


	return 0;
}