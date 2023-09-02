#pragma once

#include <QDebug>
#include <deque>

class RotateArray
{
public:
    //-----------------------------------
    //Time complexity: O(n)
    //Space complexity: O(n)
    void rotate(std::vector<int>& nums, int k)
    {
        std::deque<int> rotated; //O(n)
        for(int i : nums) //O(n)
        {
            rotated.push_back(i);
        }
        //Here we cannot do --k, that would mean we will first decrease the K
        //then only enter the loop. But we want to enter the k and then decrement the loop.
        //Otherwise, we will always have 1 less iteration.
        //In the case of k--, the decrement occurs after the loop body execution,
        //while in the case of --k, the decrement occurs before the loop condition check.
        while(k--) //O(k)
        {
            int value = rotated.back();
            rotated.push_front(value);
            rotated.pop_back();
        }

        nums.clear();
        while(!rotated.empty())//O(n)
        {
            nums.push_back(rotated.front());
            rotated.pop_front();
        }
    }

    //-----------------------------------
    //Time complexity: O(n)
    //Space complexity: O(n)
    void rotateAnotherWay(std::vector<int>& nums, int k)
    {
        int n = nums.size();
        std::vector<int> result(n);
        for(int i = 0; i < nums.size(); ++i)
        {
            int new_index = (i + k) % n;
            result[new_index] = nums[i];
        }

        nums = result;
    }

    //-----------------------------------
    //Time complexity: O(n)
    //Space complexity : O(1)
    void rotateOptimalSolution(std::vector<int>& nums, int k)
    {
        //When k is larger than the nums size, then it's actually point less to keep rotating.
        //And also when rotating using index/iterator if nums size is smaller than k, doing
        //operation using this value of k will cause invalid pointer access.
        k %= nums.size();

        //steps:
        //reverse the nums vector
        //reverse the first k element from the reversed vector
        //reverse the rest of the elemts from the reversed vector
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};


namespace test
{
    void RotateArrayTests()
    {
        RotateArray rotate;
        std::vector<int> to_rotate{1,2,3,4,5,6,7};
        rotate.rotateOptimalSolution(to_rotate, 3);
        qWarning() << to_rotate; //expected: 5 6 7 1 2 3 4
    }
}
