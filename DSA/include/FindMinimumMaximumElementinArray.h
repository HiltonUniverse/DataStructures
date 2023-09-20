#pragma once

#include <QDebug>

class FindMinimumMaximumElementinArray
{
public:
    std::pair<int, int> getMinMax(std::vector<int>& nums, int n)
    {
        int l = 0;
        int r = 0;
        int max = INT_MIN;
        int min = INT_MAX;

        while(r < nums.size())
        {
            max = std::max(max, std::max(nums[l], nums[r]));
            min = std::min(min, std::min(nums[l], nums[r]));
            ++l;
            ++r;
        }

        return {min, max};
    }

    //-----------------------------------
    std::pair<int, int> getMinMaxQuick(std::vector<int>& nums, int n)
    {
        const auto iters = std::minmax_element(nums.begin(), nums.end());
        return {*iters.first, *iters.second};
    }
};


namespace test
{
    void FindMinimumMaximumElementinArrayTests()
    {
        FindMinimumMaximumElementinArray min_max;
        std::vector<int> find_1{3, 2, 1, 56, 10000, 167};
        qWarning() << min_max.getMinMax(find_1, find_1.size()); //1 10000

        std::vector<int> find_2{1, 345, 234, 21, 56789};
        qWarning() << min_max.getMinMax(find_2, find_2.size()); //1-56789
    }
}
