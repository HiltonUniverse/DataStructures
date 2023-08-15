#pragma once

#include <QDebug>
#include <vector>

class MonotonicArray
{
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    bool isMonotonic(const std::vector<int>& nums)
    {
        bool increasing = true;
        bool decreasing = true;

        //size - 1 because don't have anything to compare the last element with when it becomes the i'th element.
        //so i+1 does not exist for the last element and the last element is considered the last element itself.
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            if(nums[i] > nums[i+1])
            {
                increasing = false;
            }

            if(nums[i] < nums[i+1])
            {
                decreasing = false;
            }
        }

        return increasing || decreasing;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void monotonicArrayTests()
    {
        MonotonicArray monotonic_array;
        qWarning() << monotonic_array.isMonotonic({1,2,2,3}); //true decreasing monotonic array
        qWarning() << monotonic_array.isMonotonic({6,5,4,4}); //true increasing monotonic array
        qWarning() << monotonic_array.isMonotonic({1,3,2}); //false neither increasing or decreasing
    }
}
