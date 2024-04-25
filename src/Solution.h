#pragma once

#include <vector>
#include <set>
#include <utility>

class Solution {
private:
    static std::pair<std::multiset<int>, std::multiset<int>> initialSlidingWindow(const std::vector<int>& nums, int k);
public:
    std::vector<double> medianSlidingWindow(const std::vector<int>& nums, int k);
};
