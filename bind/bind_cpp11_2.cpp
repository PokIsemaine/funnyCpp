// bind 和 function 实现线程池
// from c++ muduo
#include <vector>
#include <functional>
#include <memory>
#include <iostream>
#include <thread>

using namespace std;

class Thread {
public:
	// 使用 function 函数对象接收绑定器
	Thread(function<void()> func) : _func(func) {}
	
	// 创建线程
	thread start() {
		thread t(_func);
		return t;
	}
private:
	function<void()> _func;
};

class ThreadPool {
public:
	ThreadPool() {}
	~ThreadPool() {
		// _pool 里面是个指针，需要自己去析构
		// 释放 Thread 对象占用的堆资源
		for (int i = 0 ; i < _pool.size(); ++i) {
			delete _pool[i];
		}
	}

	// 开启线程池
	void startPool(int size) {
		for(int i = 0; i < size; ++i) {
			// _pool.push_back(new Thread());
			// 使用 bind 绑定 注意因为成员方法自带一个 this, 所以还要绑定一个 this 参数
			_pool.push_back(new Thread(bind(&ThreadPool::runInThread, this, i)));
		}

		for(int i = 0 ; i < size; ++i) {
			_handler.push_back(_pool[i]->start());
		}

		for(thread &t : _handler) {
			t.join();
		}
	}
private:
	// _pool 里面是个指针，需要自己去析构
	vector<Thread*> _pool;
	vector<thread> _handler;

	// 把 runInThread 这个成员方法充当线程函数
	// C++ 的 thread 和 Linux pthread_create 需要的线程函数都是一个 C 函数，不能使用成员方法
	// 使用 bind 来绑定
	void runInThread(int id) {
		cout <<"call runInThread! id: " << id << endl;
	}
};

int main() {
	ThreadPool pool;
	pool.startPool(10);
}