#include "Solution.h"


#include <iostream>

SlidingWindow Solution::initialSlidingWindow(const Nums& nums, int k) {
	SlidingWindowPart window(nums.begin(), std::next(nums.begin(), k));
	const int border_index = k / 2;
	auto border_iterator = std::next(window.begin(), border_index);
	SlidingWindowBack back(border_iterator, window.end());
	window.erase(border_iterator, window.end());
	return std::make_tuple(std::move(window), std::move(back), 0);
}

Medians Solution::medianSlidingWindow(const Nums& nums, int k) {
	// TODO: completed implementation
	auto [front, back, start_index] = initialSlidingWindow(nums, k);

	for (const auto& m : front) { std::cout << m << " "; } std::cout << std::endl;
	for (const auto& m : back) { std::cout << m << " "; } std::cout << std::endl;
        std::cout << start_index << std::endl;

	return {};
}
