#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <ctime>

using namespace std;

template<typename Container>
void showContainer(Container &con) {
	for(auto e: con) {
		cout << e << " ";
	}
	cout <<endl;
}


template<typename Iterator, typename Compare>	//Compare 应该是一个一元函数对象
Iterator my_find_if(Iterator first, Iterator last, Compare comp) {
	for(; first != last; ++first) {
		if(comp(*first)) {	// comp.operator() (*first)
			return first;
		}
	}
}

template<typename Compare, typename T>
class _mybind1st {
public:
	_mybind1st(Compare comp, T val) 
		: _comp(comp), _val(val) {};

	bool operator() (const T& second) {
		return _comp(_val, second);
	}
private:
	Compare _comp;
	T _val;
};

//mybind1st(greater<int>(), 70);
template<typename Compare, typename T>
_mybind1st<Compare,T> mybind1st (Compare comp, const T& val) {
	// 直接使用函数模板好处是可以进行类型的推演
	// 传入一个二元函数对象和常数，返回一个一元函数对象
	return _mybind1st<Compare, T> (comp, val);
}



int main() {

	vector<int> vec;
	srand(time(nullptr));

	for(int i = 0; i < 20; ++i) {
		vec.push_back(rand() % 100 + 1);
	}

	showContainer(vec);

	sort(vec.begin(),vec.end());	// 默认小到大排序

	showContainer(vec);

	sort(vec.begin(),vec.end(),greater<int>());	// 大到小排序

	showContainer(vec);

	/*
		把 70 按顺序插入到 vec 容器当中 找第一个小于 70 的数字
		需要一个一元的函数对象 operator() (const T& val)
		greater a > b
		less a < b
		库里面提供的函数对象都是二元的
		那么就需要 bind1st bind2st 来绑定
		绑定器 + 二元函数对象 ===> 一元函数对象
		bind1st：greater bool operator(70, const _Ty& _Right)
		bind2st： bool operator(const _Ty& _Left, 70)
	*/
	auto it1 = my_find_if(vec.begin(), vec.end(), mybind1st(greater<int>() , 70));
	
	if(it1 != vec.end()) {
		vec.insert(it1, 70);
	}

	showContainer(vec);

	return 0;
}