#include <fmt/format.h>
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <fmt/ranges.h>
#include <fmt/os.h>
#include <fmt/color.h>
#include <vector>

//https://github.com/fmtlib/fmt#speed-tests
// -l fmt

int main() {
  	fmt::print("Hello, world!\n");

  	std::string s = fmt::format("The answer is {}.", 42);
	// s == "The answer is 42."

	std::string s2 = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
	// s == "I'd rather be happy than right."

	using namespace std::literals::chrono_literals;
 	fmt::print("Default format: {} {}\n", 42s, 100ms);
  	fmt::print("strftime-like format: {:%H:%M:%S}\n", 3h + 15min + 30s);

	std::vector<int> v = {1, 2, 3};
	fmt::print("{}\n", v);

// This gives a compile-time error in C++20 because d is an invalid format specifier for a string.
	// std::string s3 = fmt::format("{:d}", "I am not a number");

	auto out = fmt::output_file("guide.txt");
  	out.print("Don't {}", "Panic");

	fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
				"Hello, {}!\n", "world");
	fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) |
				fmt::emphasis::underline, "Hello, {}!\n", "мир");
	fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic,
				"Hello, {}!\n", "世界");
}