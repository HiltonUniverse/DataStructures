#pragma once

#include <QDebug>
#include <set>

class RemoveDuplicateFromSortedArray
{
public:
    //-----------------------------------
    //Time complexity: O(n)
    //Space complexity: O(n)
    int removeDuplicatesUsingSet(std::vector<int>& nums)
    {
        std::set<int> unique_nums;
        for(int i : nums)
        {
            unique_nums.insert(i);
        }

        //we do this because normally nums is also tested by the caller for it's uniqueness
        nums.clear();
        for(int i : unique_nums)
        {
            nums.push_back(i);
        }

        return unique_nums.size();
    }

    //-----------------------------------
    //Time complexity: O(n)
    //Space complexity: O(1)
//    int removeDuplicates(std::vector<int>& nums)
//    {
//    }
};

namespace test
{
    void RemoveDuplicateFromSortedArrayTests()
    {
        RemoveDuplicateFromSortedArray remove;
        {
            std::vector<int> nums{1,1,2};
            qWarning() << remove.removeDuplicatesUsingSet(nums); //expected [1,2]

            std::vector<int> nums_2{0,0,1,1,1,2,2,3,3,4};
             qWarning() << remove.removeDuplicatesUsingSet(nums_2); //expected [0,1,2,3,4]

             std::vector<int> nums_3{3,3};
             qWarning() << remove.removeDuplicatesUsingSet(nums_3); //expected [3]
        }

    }
}
