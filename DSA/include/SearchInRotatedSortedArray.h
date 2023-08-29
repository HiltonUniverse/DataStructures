#pragma once

#include <QDebug>

class SearchInRotatedSortedArray
{
public:
    //Time complexity : O(log n)
    //Space complexity: O(1)
    int search(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
            {
                return mid;
            }

            //This part is just to select the correct array partition to find our target
            //>=, the equals(=) is essential beecause if we have 2 inputs [3 1], and target = 1. Then mid and left point to same element.
            //In such case,we want the left pointer to move to the right which happens in the else part of this if condition.
            if(nums[mid] >= nums[0])
            {
                if(target >= nums[0] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void searchInRotatedsortedArrayTests()
    {
        SearchInRotatedSortedArray search;
        std::vector<int> nums{4,5,6,7,0,1,2};
        qWarning() << search.search(nums,0); // 4
        std::vector<int> nums_2{3,1};
        qWarning() << search.search(nums_2, 1); // 1
    }
}
