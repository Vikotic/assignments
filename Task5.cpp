#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

std::vector<double> sortTemperatures(const std::vector<double>& readings)
{
	const double LOWEST  = 97.0;     // minimum temperature
	const double HIGHEST = 99.0;     // maximum temperature
	const int    SLOTS   = 21;       // 97.0 to 99.0 has 21 different numbers if we only go to tenth decimals

	// Create a frequency table (21 slots, all start at 0)
	std::vector<int> freq(SLOTS, 0);

	// Counting each reading gives a single O(N) loop
	for (double temp : readings) {
		if (temp < LOWEST || temp > HIGHEST) {
			throw std::out_of_range("Temperature outside 97.0 to 99.0 F");
		}
		// Map 97.0 turns into 0, 97.1 to 1, 99.0 to 20 and each index counts how many times the temp shows up
		int index = static_cast<int>((temp - LOWEST) * 10 + 0.5); // we add 0.5 because ints don't count the exact number and can result in something like 97.9999999999 which might mess up our count
		freq[index]++;               // add to the counter in that slot
	}

	// Build the sorted list from the counts
	std::vector<double> sorted;
	sorted.reserve(readings.size()); // avoid reallocations

	for (int slot = 0; slot < SLOTS; ++slot) {
		double value = LOWEST + 0.1 * slot;     // convert slot back to temp
		for (int count = 0; count < freq[slot]; ++count) {
			sorted.push_back(value);            // write it out 'count' times
		}
	}
	return sorted;  // finished, overall O(N)
}

int main()
{
	// given example data
	std::vector<double> temps = {
		98.6, 98.0, 97.1, 99.0, 98.9,
		97.8, 98.5, 98.2, 98.0, 97.1
	};

	// Sort our temps including duplicates
	std::vector<double> sorted = sortTemperatures(temps);

	// Print out our values in order
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Sorted temperatures:\n";
	for (double t : sorted) {
		std::cout << t << ' ';
	}
	std::cout << '\n';
	return 0;
}