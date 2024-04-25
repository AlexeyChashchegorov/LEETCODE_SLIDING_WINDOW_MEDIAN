#pragma once

#include <vector>
#include <set>
#include <utility>


using Median             = double;
using Medians            = std::vector<double>;

using Nums               = std::vector<int>;
using SlidingWindowPart  = std::multiset<int>;
using SlidingWindowFront = SlidingWindowPart;
using SlidingWindowBack  = SlidingWindowPart;
using SlidingWindow      = std::pair<SlidingWindowFront, SlidingWindowBack>;
