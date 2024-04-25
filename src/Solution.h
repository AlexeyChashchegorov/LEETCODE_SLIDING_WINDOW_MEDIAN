#pragma once

#include <vector>
#include <set>

class Solution {
private:
    static std::multiset<int> initialSlidingWindow(const std::vector<int>& nums, int k);
public:
    std::vector<double> medianSlidingWindow(const std::vector<int>& nums, int k);
};
