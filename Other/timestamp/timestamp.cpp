#include <ios>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <numeric>

volatile int sink;

// 使用std::chrono::xxx_clock::now() 来获取时间戳，有可能会引入 syscall 而影响性能

int main() {
	std::cout << std::fixed << std::setprecision(9) <<  std::left;
	for(auto size = 1ull; size < 1000'000'000ull; size *= 100) {
		//record start time 
		auto start =  std::chrono::steady_clock::now();
		//do some work
		std::vector<int> v(size, 42);
		sink = std::accumulate(v.begin(),v.end(),0u);	//make sure it's a side effect
		//record end time
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout <<"Time to fill and iterate a vector of " << std::setw(9)
				<< size << "ints: " << diff.count() << " s\n";
	}

	return 0;
}
