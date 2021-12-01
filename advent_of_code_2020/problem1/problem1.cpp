#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace example {
	std::string input{ R"(1721
979
366
299
675
1456)" };
}

std::vector<int> parse_numbers(std::istream& t_is)
{
	std::vector<int> numbers{};
	for (std::string line; std::getline(t_is, line);) {
		numbers.push_back(std::stoi(line));
	}
	return numbers;
}

int solve_part1(const std::vector<int>& t_numbers)
{
	int result{};
	for (int i = 0; i < t_numbers.size(); ++i) {
		for (int j = i + 1; j < t_numbers.size(); ++j) {
			if (t_numbers[i] + t_numbers[j] == 2020) {
				result = t_numbers[i] * t_numbers[j];
				break;
			}
		}
	}
	return result;
}

int solve_part2(const std::vector<int>& t_numbers)
{
	int result{};
	for (int i = 0; i < t_numbers.size(); ++i) {
		for (int j = i+1; j < t_numbers.size(); ++j) {
			for (int k = j + 1; k < t_numbers.size(); ++k) {
				if (t_numbers[i] + t_numbers[j] + t_numbers[k] == 2020) {
					result = t_numbers[i] * t_numbers[j] * t_numbers[k];
					break;
				}
			}
		}
	}
	return result;
}

int main()
{
	std::istringstream iss{ example::input };
	auto example_numbers{ parse_numbers(iss) };
	std::cout << "Example 1: " << solve_part1(example_numbers) << '\n';

	std::string filename{ "input.txt" };
	std::ifstream infile{ filename };
	auto numbers{ parse_numbers(infile) };
	std::cout << "Part 1: " << solve_part1(numbers) << '\n';

	std::cout << "Example 2: " << solve_part2(example_numbers) << '\n';
	std::cout << "Part 2: " << solve_part2(numbers) << std::endl;
	return 0;
}