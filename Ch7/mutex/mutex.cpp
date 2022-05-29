#include <iostream>
#include <mutex>
#include <thread>

int v = 1;

void critical_section_unique(int change_v) {
	static std::mutex mtx;
	// unique_lock 独占所有权的方式 mutex 对象上的上锁和解锁操作
	// 没有其他的 unique_lock 对象同时拥有某个 mutex 对象的所有权

	// 相比lock_guard 可以缩小锁的范围, 提高并发度
	std::unique_lock<std::mutex> lock(mtx);

	v = change_v;
	std::cout << v << std::endl;

	lock.unlock();

	// 可以自己手动加锁解锁
	lock.lock();
	v += 1;
	std::cout << v << std::endl;
}

void critical_section_RAII(int change_v) {
	static std::mutex mtx;
	
	// RAII 的 lock_guard 比成对调用 mutex 成员函数 lock 和 unlock 要好一些
	// 简洁并且异常安全
	std::lock_guard<std::mutex> lock(mtx);

	//执行竞争操作
	v = change_v;

	// 离开作用域后 mtx 会被释放,自动调用 unlock
	// lock.unlock(); 编译报错，实际上 lock_guard 通过构造和析构函数来管理上锁和解锁
	// unqiue_lock 更自由
}


void critical_section(int change_v) {
	static std::mutex mtx;
	
	mtx.lock();

	v = change_v;

	mtx.unlock();
}
int main() {
	std::thread t1(critical_section_unique, 2), t2(critical_section_unique, 3);
	t1.join();
	t2.join();

	std::cout << v << std::endl;
	return 0;
}
