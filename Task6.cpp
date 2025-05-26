#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stdexcept>

int longestConsecutive(const std::vector<int>& nums)
{
	if (nums.empty()) return 0;

	// Put every number into an unordered_set for O(1) lookups.
	std::unordered_set<int> table(nums.begin(), nums.end());

	int best = 0;

	//Iterate over each distinct number in our array
	for (int num : table) {
		// Only try to build a sequence from numbers that are in the set
		// num - 1 is not in the set
		if (table.find(num - 1) == table.end()) {
			int length = 1;
			int current = num;

			// Extend the sequence as long as there are consecutive numbers
			while (table.find(current + 1) != table.end()) {
				current++;
				length++;
			}
			best = std::max(best, length);
		}
	}
	return best;
}

int main()
{
	std::vector<int> ex1 {10, 5, 12, 3, 55, 30, 4, 11, 2};   // expect 4 (2,3,4,5)
	std::vector<int> ex2 {19, 13, 15, 12, 18, 14, 17, 11};    // expect 5 (11,12,13,14,15)

	std::cout << "Longest consecutive (ex1): "
	          << longestConsecutive(ex1) << '\n';
	std::cout << "Longest consecutive (ex2): "
	          << longestConsecutive(ex2) << '\n';

	return 0;
}