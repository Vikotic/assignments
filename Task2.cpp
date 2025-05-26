#include <iostream>
#include <vector>
#include <cstdint>


int findMissingSum(const std::vector<int>& nums)
{
	const std::size_t N = nums.size();          // note: array has N items = one missing from 0 to N

	// expected sum of 0 + 1 + ... + N  (use 64bit to avoid overflow)
	uint64_t expected = static_cast<uint64_t>(N) * (N + 1) / 2;

	uint64_t actual = 0;
	for (int v : nums) actual += v;             // O(N)

	return static_cast<int>(expected - actual); // difference is the missing value
}

// main
int main()
{
	std::vector<int> example1 {2, 3, 0, 6, 1, 5};
	std::vector<int> example2 {8, 2, 3, 9, 4, 7, 5, 0, 6};

	std::cout << "Missing (sum)  example1: " << findMissingSum(example1) << '\n';  // 4

	std::cout << "Missing (sum)  example2: " << findMissingSum(example2) << '\n';  // 1

	return 0;
}

