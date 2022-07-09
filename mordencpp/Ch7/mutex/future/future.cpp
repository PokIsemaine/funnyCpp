#include <thread>
#include <future>
#include <iostream>

int sum1 (int a, int b) {
	return a + b;
}
int sum2 (int a, int b, int c) {
	return a + b + c;
}

int main() {

	std::packaged_task<int(int,int)> task1(sum1);

	std::future<int> res = task1.get_future();

	std::thread t(std::move(task1), 10 , 20);
	t.detach();
	
	// 得到结果之前会阻塞
	std::cout << res.get() << std::endl;

#if 0

	std::packaged_task<int()> task([](){ return 7;});
	
	// 获得 task 的期物
	std::future<int> result = task.get_future();	//在一个线程中执行 task

	std::thread(std::move(task)).detach();

	std::cout << "waiting...";

	result.wait();	//在此设置屏障，阻塞到期物完成
				
	std::cout << "done!" << std::endl << "future result is " << result.get() << std::endl;

#endif
	return 0;
}
