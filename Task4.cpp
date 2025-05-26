#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdint>

long long maxProductOfTwo(const std::vector<int>& nums)
{
	if (nums.size() < 2) {
		throw std::invalid_argument("Need at least two numbers");
		// error in case only one number is plugged in
	}

	// Seed the trackers with the first two values, already ordered.
	int first = nums[0];
	int second = nums[1];

	int max1 = std::max(first, second); // largest so far
	int max2 = std::min(first, second); // 2nd largest

	int min1 = std::min(first, second); // smallest so far
	int min2 = std::max(first, second); // 2nd smallest

	// Process the remaining elements
	for (std::size_t i = 2; i < nums.size(); ++i) {
		int x = nums[i];

		// Update the two largest values
		if (x > max1) {
			max2 = max1;
			max1 = x;
		} else if (x > max2) {
			max2 = x;
		}

		// Update the two smallest values
		if (x < min1) {
			min2 = min1;
			min1 = x;
		} else if (x < min2) {
			min2 = x;
		}
	}

// multiplies the two largest positive numbers together and the two smallest negative numbers together.
	long long prodMax   = static_cast<long long>(max1) * max2;
	long long prodMin   = static_cast<long long>(min1) * min2;

// compares the two numbers and checks which one is larger
	return std::max(prodMax, prodMin);
}

//main
int main()
{
	std::vector<int> example {5, -10, -6, 9, 4};

	std::cout << "Highest product of two (no numeric_limits): "
	          << maxProductOfTwo(example) << '\n';  // Expected 60 = -10 * -6

	return 0;
}
