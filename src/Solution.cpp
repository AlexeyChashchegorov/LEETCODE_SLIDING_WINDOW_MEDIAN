#include "Solution.h"


#include <iostream>

std::multiset<int> Solution::initialSlidingWindow(const std::vector<int>& nums, int k) {
	return std::multiset<int>(nums.begin(), std::next(nums.begin(), k));
}

std::vector<double> Solution::medianSlidingWindow(const std::vector<int>& nums, int k) {
	// TODO: completed implementation
	for (const auto& m : initialSlidingWindow(nums, k)) {
		std::cout << m << " ";
	} std::cout << std::endl;
	return {};
}
