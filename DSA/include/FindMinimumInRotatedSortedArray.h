#pragma once

#include <QDebug>

class FindMinimumInRotatedSortedArray
{
public:
    //Time complexity: O(log n)
    //Space complexity: O(1)
    int findMin(std::vector<int>& nums)
     {
         //if only one element, that is the minimum
         if(nums.size() == 1)
         {
             return nums[0];
         }

         /*
         Find the mid element i.e. mid = low + (high - low)/2
         If the (mid+1) element is less than (mid) element then return (mid+1) element
         If the last element is greater than mid element then search in left half
         If the last element is less than mid element then search in right half
         */
         int left = 0;
         int right = nums.size() - 1;
         while(left <= right)
         {
             int mid = left + (right - left)/2;
             if(nums[mid+1] < nums[mid])
             {
                 return nums[mid+1];
             }
             else if(nums[mid] > nums[right])
             {
                 left = mid + 1;
             }
             else
             {
                 right = mid - 1;
             }
         }

         return  nums[left];
     }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void findMinimumInRotatedSortedArrayTests()
    {
        FindMinimumInRotatedSortedArray find_min;
        std::vector<int> pile{3,4,5,1,2};
        qWarning() << find_min.findMin(pile); // 1

        std::vector<int> pile_2{4,5,6,7,0,1,2};
        qWarning() << find_min.findMin(pile_2); // 0

        std::vector<int> pile_3{11,13,15,17};
        qWarning() << find_min.findMin(pile_3); // 11

        std::vector<int> pile_4{4,5,1,2,3};
        qWarning() << find_min.findMin(pile_4); // 1

    }
}
