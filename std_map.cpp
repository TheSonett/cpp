#include <iostream>
#include <vector>

#include <map> // sorted map -> It's a self-balancing binary search tree called Red-Black Tree.
#include <unordered_map> // unsorted map -> It's a hash table. It uses the hash function to hash your key.

struct CityRecord
{
	std::string Name;
	uint64_t Population;
	double Latitude, Longitude;

	bool operator<(const CityRecord& other) const {
		return Population < other.Population;
	}
};

namespace std {
	template<>
	struct hash<CityRecord>
	{
		size_t operator()(const CityRecord& key) const noexcept {
			return hash<std::string>{}(key.Name);
		}
	};
}

int main()
{
	/*std::vector<CityRecord> cities;
	cities.emplace_back("Kolkata", 300000, 3.4, 1.2);
	cities.emplace_back("Mumbai", 40000, 5.4, 3.1);
	cities.emplace_back("Goa", 500000, 6.4, 3.5);
	cities.emplace_back("Delhi", 70000, 8.4, 8.8);

	std::vector<CityRecord>::iterator city;
	for (city = cities.begin(); city != cities.end(); city++) {
		if (city->Name == "Goa") {
			std::cout << city->Population << std::endl;
			break;
		}
	}*/

	std::map<CityRecord, uint32_t> cityFounded; // not hashable normally
	cityFounded[CityRecord{ "Kolkata", 300000, 3.4, 1.2 }];

	std::unordered_map<std::string, CityRecord> cityMap;
	cityMap["Kolkata"] = CityRecord{"Kolkata", 300000, 3.4, 1.2};
	cityMap["Mumbai"] = CityRecord{ "Mumbai", 40000, 5.4, 3.1 };
	cityMap["Goa"] = CityRecord{ "Goa", 500000, 6.4, 3.5 };
	cityMap["Delhi"] = CityRecord{ "Delhi", 70000, 8.4, 8.8 };

	for (auto& [name, city] : cityMap) {
		std::cout << name << "\n Population: " << city.Population << std::endl;
		cityFounded[city] = 0;
		if (city.Name == "Kolkata") {
			cityFounded[city] = 1686;
		}
	}

	printf("\n\n");

	for (auto& [city, founded] : cityFounded) {
		std::cout << city.Name << "\n Founded in: " << founded << std::endl;
		cityFounded[city] = 0;
	}

	std::cin.get();
}