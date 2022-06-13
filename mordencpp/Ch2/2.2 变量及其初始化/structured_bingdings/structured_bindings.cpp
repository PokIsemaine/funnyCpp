#include <iostream>
#include <string>
#include <tuple>
std::tuple<int, double, std::string> f() {
	return std::make_tuple(1, 2.3, "abc");
}
int main() {
	//before C++17
	std::tuple<int,double,std::string> ans = f();
	auto a = std::get<0>(ans);
	auto b = std::get<1>(ans);
	auto c = std::get<2>(ans);
	std::cout << a << " " << b << " " << c << std::endl;

	int p;
	double q;
	std::string r;
	std::tie(p,q,r) = f();
	std::cout << p << " " << q << " " << r << std::endl;

	//after C++17
	auto[x, y, z] = f();
	std::cout << x << " " << y << " " << z << std::endl;
	
	return 0;
}