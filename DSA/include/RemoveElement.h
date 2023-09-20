#pragma once

#include <QDebug>

class RemoveElement
{
public:
    //Time complexity: O(n)
    //Space complexity: O(1)
    int removeElement(std::vector<int>& nums, int val)
    {
        int count = 0;
        for(int i : nums) //O(n)
        {
            if(i == val)
            {
                //std::remove = O(n)
                //std::erase = O(n) - it might have to remove all the elements worst case
                nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
                ++count;
            }
        }

        for(int i = 0; i < count; ++i) //O(count)
        {
            nums.push_back(val);
        }

        return nums.size() - count;
    }

    //-----------------------------------
    //Time complexity: O(n)
    //space complexity : O(1)
    int removeElementTwoPointers(std::vector<int>& nums, int val)
    {
        int l = 0;
        int r = 0;
        int count = 0;
        //move all elements we want to remove to the end
        while( r < nums.size() )
        {
            if(nums[r] == val)
            {
                ++count;
                ++r;
            }
            else
            {
                if(r != l)
                {
                    std::swap(nums[r], nums[l]);
                }
                ++r;
                ++l;
            }
        }

        //return the size of values that are not to be removed
        return nums.size() - count;
    }
};

namespace test
{
    void RemoveElementTests()
    {
        RemoveElement remove;
        {
            std::vector<int> nums{3,2,2,3};
            qWarning() << remove.removeElementTwoPointers(nums, 3); //expected 2

            std::vector<int> nums_2{5,4,3,2,0,0}; // 5 4 3 2 0 0
             qWarning() << remove.removeElementTwoPointers(nums_2, 0); //expected 4

             std::vector<int> nums_3{3,3};
             qWarning() << remove.removeElementTwoPointers(nums_3, 3); //expected 0

        }

    }
}
