#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>

std::vector<std::vector<int>> findPerms(std::vector<int> freq, int k)
{
	std::vector<std::vector<int>> total;
	std::vector<int> p;

	std::iota(freq.begin(), freq.end(), 1);
	do
	{
		for (int i = 0; i < k; i++)
		{
			std::cout << freq[i] << " ";
			p.push_back(freq[i]);
		}
		std::cout << std::endl;
		std::reverse(freq.begin() + k, freq.end());
		total.push_back(p);
		p.clear();

	} while (next_permutation(freq.begin(), freq.end()));

	return total;
}

int main()
{
	int length = 2;
	std::vector<int> freq = { 1,2,3,4 };
	while (1){
		int input;
		std::vector<std::vector<int>> freq_new;
		std::cout << "input permutation size: ";
		std::cin >> input;
		freq_new = findPerms(freq, input);
		std::cout << "here";
	}
	
	return 0;
}
