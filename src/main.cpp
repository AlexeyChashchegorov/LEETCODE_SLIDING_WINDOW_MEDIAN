#include "Solution.h"

#include <iostream>

int main() {
	std::vector<int> nums;
	int k;
	while (!(std::cin >> k).eof())
		nums.emplace_back(k);

	nums.pop_back();
	std::cout << "nums:";
	for(const auto& num : nums)
		std::cout << num << " ";
	std::cout << ", k:" << k << std::endl;

	for(const auto& median: Solution().medianSlidingWindow(nums, k))
		std::cout << median << " ";
	std::cout << std::endl;
	return 0;
}
