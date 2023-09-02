#pragma once

#include <QDebug>

class MoveZeros
{
public:
    //Time complexity: O(n)
    //space complexity : O(1)
    void moveZeroes(std::vector<int>& nums)
    {
        int left = 0;
        int right = 0;
        while(right < nums.size())
        {
            if(nums[right] != 0)
            {
                std::swap(nums[left], nums[right]);
                ++left;
                ++right;
            }
            else
            {
                ++right;
            }
        }
    }

    //-----------------------------------
    //Time complexity: O(n)
    //space complexity : O(1)
    void another(std::vector<int>& nums)
    {
        int l = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
            {
                if(i != l) //don't perform swap if i == l, no point
                {
                    std::swap(nums[i], nums[l]);
                }
                ++l;
            }
        }
    }
};

namespace test
{
    void MoveZerosTests()
    {
        MoveZeros move;
        {
            std::vector<int> nums{0,1,0,3,12};
            move.moveZeroes(nums);
            qWarning() << nums; //expected 1 3 12 0 0

            std::vector<int> nums_2{5,4,3,2,0,0}; // 5 4 3 2 0 0
            move.moveZeroes(nums_2);
            qWarning() << nums_2;
        }

        {
            //test another
            std::vector<int> nums{0,1,0,3,12};
            move.another(nums);
            qWarning() << nums; //expected 1 3 12 0 0

            std::vector<int> nums_2{5,4,3,2,0,0}; // 5 4 3 2 0 0
            move.another(nums_2);
            qWarning() << nums_2;

            std::vector<int> nums_3{1,2,7,0,1,2,4}; // 1 2 7 1 2 4 0
            move.another(nums_3);
            qWarning() << nums_3;
        }

    }
}
