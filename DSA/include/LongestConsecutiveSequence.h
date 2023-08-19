#pragma once

#include <QDebug>
#include <unordered_set>

class LongestConsecutiveSequence
{
    /*
     * Time complexity: O(n), we do not consider the while loop significant enough to multiple for and while together.
     *                  While loop runs a constant time and is independent of the input size. Even though the worst case it runs O(n).
     *                  But there will mostly be a lot of sequence and while loop won't be running n times.
     * Space complexity: O(n)
     */
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        std::unordered_set<int> sequence(nums.begin(), nums.end());
        int longest = 0;
        for(int num : sequence)
        {
            if(sequence.count(num - 1)) //if has left neighbour skip loop
            {
                continue;
            }

            int length = 1;
            while(sequence.count(++num))
            {
                ++length;
            }
            longest = std::max(longest, length);
        }

        return longest;
    }

    //-----------------------------------
    int longestConsecutiveNLogN(std::vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int final_count = 0;
        int temp_count = 1;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > 0 && nums[i] != nums[i - 1])
            {
                //This is unique, we check if i is a +1 of whatever number before it.
                //so in 1,2,3,4... if i points to 2, then we check if a 2 is a number we get after adding a 1 to i - 1.
                //nice way of checking!
                if(nums[i] == nums[i-1]+1)
                {
                    ++temp_count;
                }
                else
                {
                    final_count = std::max(final_count, temp_count);
                    temp_count = 1;
                }
            }
        }

        return std::max(final_count, temp_count);
    }

    //-----------------------------------
    int longestConsecutiveOn(std::vector<int>& nums)
    {
        std::unordered_set<int> unique_elements(nums.begin(), nums.end());

        int count = 0;
        for(int num : nums)
        {
            if(unique_elements.count(num - 1))
            {
                continue;
            }

            int temp_count = 1;
            while(unique_elements.count(num + temp_count))
            {
                ++temp_count;
            }
            count = std::max(count, temp_count);
        }

        return count;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    //-----------------------------------
    void longestConsecutiveSequenceTest()
    {
        LongestConsecutiveSequence sequence;
        std::vector<int> nums{100,4,200,1,3,2};
        //qWarning() << sequence.longestConsecutiveOn(nums);
        qWarning() << (sequence.longestConsecutive(nums) == 4);

        std::vector<int> nums_second{0,3,7,2,5,8,4,6,0,1};
        //qWarning() << sequence.longestConsecutiveOn(nums_second);
        qWarning() << (sequence.longestConsecutive(nums_second) == 9);

        std::vector<int> nums_third{0, 0};
        //qWarning() << sequence.longestConsecutiveOn(nums_third); //expected 1

        std::vector<int> nums_fourth{0,0,-1};
        qWarning() << sequence.longestConsecutiveOn(nums_fourth); //expected 2
    }
}
