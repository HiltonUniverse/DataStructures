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
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    //-----------------------------------
    void longestConsecutiveSequenceTest()
    {
        LongestConsecutiveSequence sequence;
        std::vector<int> nums{100,4,200,1,3,2};
        qWarning() << sequence.longestConsecutive(nums);
        qWarning() << (sequence.longestConsecutive(nums) == 4);

        std::vector<int> nums_second{0,3,7,2,5,8,4,6,0,1};
        qWarning() << sequence.longestConsecutive(nums_second);
        qWarning() << (sequence.longestConsecutive(nums_second) == 9);

    }
}
