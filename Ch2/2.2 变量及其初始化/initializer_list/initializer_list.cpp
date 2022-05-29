#include <initializer_list>
#include <iostream>
#include <vector>

class Foo {
	public:
		int value_a;
		int value_b;
		Foo(int a, int b) : value_a(a), value_b(b) {}
};

class MagicFoo {
public:
	std::vector<int> vec;
	// 初始列表化构造函数
	MagicFoo(std::initializer_list<int> list) {	
		for(std::initializer_list<int>::iterator it = list.begin();
			it != list.end(); ++it) 
				vec.push_back(*it);
	}
	//初始化列表作为函数参数
	void foo(std::initializer_list<int> list) {
		for(std::initializer_list<int>::iterator it = list.begin();
			it != list.end(); ++it) vec.push_back(*it);
	}
};

int main() {
	// before C++11
	int arr[3] = {1, 2, 3};
	Foo foo(1, 2);
	std::vector<int> vec = {1, 2, 3, 4, 5};

	std::cout << "arr[0]: " << arr[0] << std::endl;
	std::cout << "foo:" << foo.value_a << ", " << foo.value_b << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << std::endl;
	}

	// after C++11
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
	
	// 可以用下面这个语法来初始化任意对象
	MagicFoo anyObject {1,2,3};

    std::cout << "magicFoo: ";
    for (std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) 
		std::cout << *it << std::endl;

	magicFoo.foo({6,7,8,9});
	return 0;
}
