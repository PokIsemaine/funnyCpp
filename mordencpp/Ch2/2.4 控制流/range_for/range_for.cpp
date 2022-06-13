#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> vec = {1, 2, 3, 4};
	
	for(auto element : vec) {	// read only
		std::cout << element << " ";
	}

	std::cout << std::endl;

	for(auto &element: vec) {	// writeable
		element += 1;
	}

	for(auto element : vec) {
		std::cout << element << " ";
	}
	return 0;
}