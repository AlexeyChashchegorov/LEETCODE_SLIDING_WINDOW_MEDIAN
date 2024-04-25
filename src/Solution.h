#pragma once

#include "types.h"

class Solution {
private:
    static SlidingWindow initialSlidingWindow(const Nums& nums, int k);
    static SlidingWindow& move(SlidingWindow& window, const Nums& nums);
public:
    Medians medianSlidingWindow(const Nums& nums, int k);
};
