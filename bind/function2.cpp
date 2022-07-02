#include <functional>
#include <iostream>
#include <string>
#include <map>

using namespace std;

void doShowAllBooks() {cout << "查看所有书籍信息" << endl;}
void doBorrow()	{ cout << "借书" << endl; }
void doBack()	{ cout << "还书" << endl;}
void doQueryBooks()	{ cout << "查询书籍" << endl;}
void LoginOut() { cout << "注销" << endl;}

// function 改写经典管理系统菜单
int main() {
	int choice = 0;
	// 函数指针也可以，不过函数指针只能接收普通函数不能接收绑定器的函数对象或者 lambda 表达式
	map<int,function<void()>> actionMap;
	actionMap.insert({1, doShowAllBooks});
	actionMap.insert({2, doBorrow});
	actionMap.insert({3, doBack});
	actionMap.insert({4, doQueryBooks});
	actionMap.insert({5, LoginOut});

	for(;;) {
		cout << "-----------------" << endl;
		cout << "1.查看所有书籍信息" << endl;
		cout << "2.借书" << endl;
		cout << "3.还书" << endl;
		cout << "4.查询书籍" << endl;
		cout << "5.注销" << endl;
		cout << "-----------------" << endl;
		cout << "请选择";
		cin >> choice;

		// switch case 不好 因为不符合开闭原则
		// 改用 function
		auto it = actionMap.find(choice);
		if(it == actionMap.end()) {
			cout << "输入数字无效,请重新选择" << endl;
		} else {
			it->second();
		}
	}
	return 0;
}