#include <thread>
#include <future>
#include <iostream>

int main() {
	std::packaged_task<int()> task([](){ return 7;});
	
	// 获得 task 的期物
	std::future<int> result = task.get_future();	//在一个线程中执行 task

	std::thread(std::move(task)).detach();

	std::cout << "waiting...";

	result.wait();	//在此设置屏障，阻塞到期物完成
				
	std::cout << "done!" << std::endl << "future result is " << result.get() << std::endl;

	return 0;
}
