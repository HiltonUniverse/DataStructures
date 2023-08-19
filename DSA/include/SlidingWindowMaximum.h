#pragma once

#include <QDebug>
#include <deque>

class SlidingWindowMaximum
{
public:
    /*
     * NAIVE APPROACH
     *
     * Time complexity : O(n * k)
     * This get's Time limit excedded(TLE) when k = 50,000 and nums is very large number.
     */
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k)
    {
        std::vector<int> output;

        int l = 0;
        int r = k - 1;
        while(r < nums.size()) //O(n)
        {
            int max = INT_MIN;
            for(int i = l; i <= r; ++i) //O(k)
            {
                max = std::max(nums[i], max);
            }
            output.push_back(max);
            max = INT_MIN;
            ++l;
            ++r;
        }

        return output;
    }

    //-----------------------------------
    // We will be storing index in the deque because it's necessary when we do l > deque.front()
    // Time complexity: O(n)
    // Space complexity: O(n)
    std::vector<int> maxSlidingWindowBetter(const std::vector<int>& nums, int k)
    {
        std::vector<int> ans;
        std::deque<int> deque;

        int l = 0;
        int r = 0;

        while(r < nums.size())
        {
            if(deque.empty())
            {
                deque.push_back(r);
            }
            else
            {
                //maintain decreasing monotonous deque
                while(!deque.empty() && nums[r] > nums[deque.back()])
                {
                    deque.pop_back();
                }

                deque.push_back(r);

                //If front() is no more on our sliding window, we remove it.
                //This is because our sliding window moves from left to right as (r + 1 >= k) condition is met.
                //this could happen for following case: deque [5, -1, -2, -3], k = 3. As k = 3, the 5 in the front must be removed now
                //as i will be pointing to -1, which is > deque.front()
                if(l > deque.front())
                {
                    deque.pop_front();
                }
            }

            //we check if the window is sized k
            //if it is, we take the first element from deque as that is the largest
            //after r reaches the window size, for every next element we will take the first element as the max.
            if(r + 1 >= k)
            {
                ans.push_back(nums[deque.front()]);
                ++l;
            }

            ++r;
        }

        return ans;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void slidingWindowMaximumTests()
    {
        SlidingWindowMaximum max;
        qWarning() << max.maxSlidingWindowBetter({1,3,-1,-3,5,3,6,7}, 3);//expected [3, 3, 5, 5, 6, 7]
        qWarning() << max.maxSlidingWindowBetter({1}, 1); //expected [1]
        qWarning() << max.maxSlidingWindowBetter({1, -1}, 1); //expected [1, -1]

        //qWarning() << max.maxSlidingWindow({1,3,-1,-3,5,3,6,7}, 3);//expected [3, 3, 5, 5, 6, 7]
        //qWarning() << max.maxSlidingWindow({1}, 1); //expected [1]
        //qWarning() << max.maxSlidingWindow({1, -1}, 1); //expected [1, -1]
    }
}
