#include "Solution.h"


#include <iostream>

std::pair<std::multiset<int>, std::multiset<int>> Solution::initialSlidingWindow(const std::vector<int>& nums, int k) {
	std::multiset<int> window(nums.begin(), std::next(nums.begin(), k));
	const int border_index = k / 2;
	auto border_iterator = std::next(window.begin(), border_index);
	std::multiset<int> back(border_iterator, window.end());
	window.erase(border_iterator, window.end());
	return std::make_pair(std::move(window), std::move(back));
}

std::vector<double> Solution::medianSlidingWindow(const std::vector<int>& nums, int k) {
	// TODO: completed implementation
	auto [front, back] = initialSlidingWindow(nums, k);

	for (const auto& m : front) { std::cout << m << " "; } std::cout << std::endl;
	for (const auto& m : back) { std::cout << m << " "; } std::cout << std::endl;
	
	return {};
}
