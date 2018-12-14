#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	std::vector<std::vector<std::string>> vars = {
		{ "татва", "таттва" },
		{ "вад", "вāд", "ваад" },
		{ "", "а", "ах̤" },
	};

	std::vector<int> index(vars.size());

	do {
		for (auto i=0; i<vars.size(); ++i) {
			std::cout << vars[i][index[i]];
		}
		std::cout << '\n';
		int num_zeros = 0;
		for (int i=0; i < index.size(); ++i) {
			if (++index[i] < vars[i].size()) {
				break;
			}
			index[i] = 0;
			++num_zeros;
		}
		// all permutations finished, we are back at all-zeroes
		if (num_zeros == vars.size()) { break; }
	} while (1);
}
