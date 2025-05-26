#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

struct Player {
	std::string firstName;
	std::string lastName;
	std::string team;
};

std::vector<std::string>
findTwoSportPlayers(const std::vector<Player>& listSport1,
                    const std::vector<Player>& listSport2)
{
	std::unordered_set<std::string> namesA;
	namesA.reserve(listSport1.size() * 2);          // spare rehashing in order to reduce our load factor

	// Phase 1: O(N)
	for (const auto& p : listSport1) {
		namesA.insert(p.firstName + " " + p.lastName);
	}

	// Phase 2: O(M)
	std::vector<std::string> result;
	for (const auto& p : listSport2) {
		std::string full = p.firstName + " " + p.lastName;
		if (namesA.erase(full)) {             // erase returns 1 if found
			result.push_back(std::move(full));
		}
	}
	return result;                            // O(K) where K <= min(N, M)
}

//main
int main()
{
	std::vector<Player> basketball_players = {
		{"Jill",  "Huang",     "Gators"},
		{"Janko", "Barton",    "Sharks"},
		{"Wanda", "Vakulskas", "Sharks"},
		{"Jill",  "Moloney",   "Gators"},
		{"Luuk",  "Watkins",   "Gators"}
	};

	std::vector<Player> football_players = {
		{"Hanzla", "Radosti",   "32ers"},
		{"Tina",   "Watkins",   "Barleycorns"},
		{"Alex",   "Patel",     "32ers"},
		{"Jill",   "Huang",     "Barleycorns"},
		{"Wanda",  "Vakulskas", "Barleycorns"}
	};

	auto duals = findTwoSportPlayers(basketball_players, football_players);

// expecting Jill Huang and Wanda Vakulskas

	std::cout << "Players in both sports:\n";
	for (const auto& name : duals) {
		std::cout << "  " << name << '\n';
	}

	return 0;
}
