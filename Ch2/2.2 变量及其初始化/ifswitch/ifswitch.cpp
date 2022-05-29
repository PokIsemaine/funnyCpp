#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> vec = {1, 2, 3, 4};
	
	//before C++17
	const std::vector<int>::iterator itr = std::find(vec.begin(),vec.end(),2);
	if(iter != vec.end()) {
		*itr = 3;
	}

	// 需要重新定义一个变量，不像下面的 for 循环那样方便，但实际下面的 for 原本可以用 itr 的
	// 但因为上面已经给 if 语句用了，所以 for 循环还是需要一个新的变量 element
	const std::vector<int>::iterator itr2 = std::find(vec.begin(),vec.end(),3);
	if(iter2 != vec.end()) {
		*itr = 4;
	}

    // 将输出 1, 4, 3, 4
   for (std::vector<int>::iterator element = vec.begin(); element != vec.end(); ++element) {
	   std::cout << *element << std::endl;
   }
		

    // C++ 17 消除了这个限制
    
	if(const std::vector<int>::iterator iter = std::find(vec.begin(),vec.end(),4);
		iter != vec.end()) {
		* iter = 5;
	}
	
	// 没影响啦
	for(std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++ iter) {
		std:: cout << *iter << std::endl;
	}

	return 0;
}
