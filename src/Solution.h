#pragma once

#include "types.h"

class Solution {
private:
    static SlidingWindow initialSlidingWindow(const Nums& nums, int k);
public:
    Medians medianSlidingWindow(const Nums& nums, int k);
};
