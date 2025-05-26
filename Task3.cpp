#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

int maxProfitOneTrade(const std::vector<int>& prices)
{
	//checks for at least two values
	if (prices.size() < 2) {
		throw std::invalid_argument("Need at least two prices to compute profit.");
	}

	int min_price_so_far = prices[0];          // best price to buy so far
	int max_profit      = 0;                  // best profit found

	// Start from day 1, we can only go forward and cannot sell before we buy
	for (std::size_t i = 1; i < prices.size(); ++i) {
		int today_price = prices[i];

		// Potential profit if selling today
		int profit_today = today_price - min_price_so_far;
		max_profit = std::max(max_profit, profit_today);

		// Record the lowest price seen so far
		min_price_so_far = std::min(min_price_so_far, today_price);
	}
	return max_profit;                         // 0 if no profitable trade
}

// main
int main()
{
	std::vector<int> prices {10, 7, 5, 8, 11, 2, 6};

	std::cout << "Max profit for example array: "
	          << maxProfitOneTrade(prices) << "\n";     // Expected: 6 = 11 - 5

	return 0;
}
