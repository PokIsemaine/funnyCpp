#include "yaml-cpp/yaml.h"
#include <iostream>

// remember to lyamp-cpp
int main() {
	YAML::Emitter out;
	out << "Hello, World!";
	std::cout << "Here's the output YAML:\n" << out.c_str();
	return 0; 
}
