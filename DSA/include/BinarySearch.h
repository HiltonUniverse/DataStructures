#pragma once

#include <QDebug>
#include <stack>
#include <map>

class BinarySearch
{
public:
    //Time complexity: O(log n)
    //Space complexity : O(1)
    int search(const std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        //<= also handles the case where we have only 1 number as input for nums.
        //In that case left == right.
        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] == target)
            {
                return mid;
            }

            if(target < nums[mid])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }

    //Bruteforce method to check if runtime improves
    //Time complexity : O(n)
    //Space complexity : O(1)
    int searchBruteforce(std::vector<int>& nums, int target)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == target)
            {
                return i;
            }
        }

        return -1;
    }
};


namespace test
{
    void binarySearchTests()
    {
        BinarySearch search;
        qWarning() << search.search({-1,0,3,5,9,12}, 9);
        qWarning() << search.search({5}, 5);
    }
}
