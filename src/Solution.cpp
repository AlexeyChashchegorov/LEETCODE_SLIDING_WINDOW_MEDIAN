#include "Solution.h"

SlidingWindow Solution::initialSlidingWindow(const Nums& nums, int k) {
	SlidingWindowPart window(nums.begin(), std::next(nums.begin(), k));
	const int border_index = k / 2;
	auto border_iterator = std::next(window.begin(), border_index);
	SlidingWindowBack back(border_iterator, window.end());
	window.erase(border_iterator, window.end());
	return std::make_tuple(std::move(window), std::move(back), 0);
}

SlidingWindow& Solution::move(SlidingWindow& window, const Nums& nums) {
	auto& [front_part, back_part, start_index] = window;
	
	const auto window_size = front_part.size() + back_part.size();
	const auto required_back_part_size = back_part.size();

	
	// Erasing element that coming out of scope
	const auto value_to_remove = nums[start_index++];
	if(const auto it_at_front = front_part.find(value_to_remove); it_at_front != front_part.end()) {
		front_part.erase(it_at_front);
	} else {
		auto it_at_back = back_part.find(value_to_remove);
		back_part.erase(it_at_back);
	}

	// Adding element that coming in scope
	const auto value_to_add = nums[start_index + window_size - 1];
	if(!back_part.empty()) {
		if (*back_part.begin() > value_to_add)
			front_part.emplace(value_to_add);
		else
			back_part.emplace(value_to_add);
	} else if (!front_part.empty()) {
		if (*front_part.rbegin() <= value_to_add)
			front_part.emplace(value_to_add);
		else
			back_part.emplace(value_to_add);

	} else {
		back_part.emplace(value_to_add);
	}
	
	// Balanicing front_part and back_part by moving elements from one part to another in case of add/delete on different parts
	// After balancing we can be sure how to detect the median fast and inline with req speq
	while (back_part.size() != required_back_part_size) {
		if (back_part.size() < required_back_part_size) {
			back_part.emplace(*front_part.rbegin());
			front_part.erase(std::prev(front_part.end())); // convert to forward iterator
		} else {
			front_part.emplace(*back_part.begin());
			back_part.erase(back_part.begin());
		}
	}

	
	return window;
}


double Solution::median(const SlidingWindow& window) {
	const auto& [ front_part, back_part, _ ] = window;
	if (front_part.size() == back_part.size())
		return (double(*prev(front_part.end())) + double(*back_part.begin())) / 2;
	return *back_part.begin();
	 
}

Medians Solution::medianSlidingWindow(const Nums& nums, int k) {
	// TODO: completed implementation
	auto window = initialSlidingWindow(nums, k);

	Medians ret;
	auto steps_count = nums.size() - k; 
	ret.reserve(steps_count);
	
	auto m = median(window);
	ret.emplace_back(median(window));

	while(steps_count-- != 0) {
		ret.emplace_back(median(move(window,nums)));
		m = median(window);
	}

	return ret;
}
