#pragma once

#include <QDebug>

class LargestDescent
{
public:
    /*
     * Sliding window to reduce Time complexity
     * Time complexity  : O(n)
     * Space complexity : O(1)
     */
    int findLargestDescent(const std::vector<int>& nums)
    {
        int l = 0;
        int r = 1;

        std::pair<int, int> min_max;

        while(r < nums.size())
        {
            if(nums[l] - nums[r] > 0)
            {
                min_max = std::minmax({min_max.first, min_max.second, nums[l], nums[r]});
            }

            ++l;
            ++r;
        }

        return min_max.second - min_max.first;
    }

    /*
     * Here we do not keep updating left ptr, it's only updated if next largest value is found
     * Time complexity  : O(n)
     * Space complexity : O(1)
     */
    int findLargestDescentAnotherWay(const std::vector<int>& nums)
    {
        int l = 0;
        int r = 1;

        int max_difference = 0;
        while(r < nums.size())
        {
            if(nums[l] > nums[r])
            {
                int difference = nums[l] - nums[r];
                max_difference = std::max(difference, max_difference);
            }
            else
            {
                l = r;
            }

            ++r;
        }

        return max_difference;
    }

    /*
     * Time complexity  : O(n^2)
     * Space complexity : O(1)
     */
    int findLargestDescentBruteForce(const std::vector<int>& nums)
    {
        int difference = 0;

        for(int i = 0; i < nums.size() - 1; ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                const int temp_diff = nums[i] - nums[j];
                if(temp_diff < 0)
                {
                    continue;
                }

                difference = std::max(difference, temp_diff);
            }
        }

        return difference;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void largestDescentTest()
    {
        LargestDescent largest_descent;
        std::vector<int> nums{5,2,3,-1,2,6,7};
        //expected largest descent: 5-(-1) = 6
        qWarning() << largest_descent.findLargestDescent(nums) << largest_descent.findLargestDescentAnotherWay(nums) << largest_descent.findLargestDescentBruteForce(nums);


        std::vector<int> nums_two{-5,-1,-4,5,1,-3,-5,-2,1,-1};
        //expected largest descent: 5-(-5) = 10
        qWarning() << largest_descent.findLargestDescent(nums_two) << largest_descent.findLargestDescentAnotherWay(nums_two) << largest_descent.findLargestDescentBruteForce(nums_two);

        std::vector<int> nums_three{0,1,2,3,4,3,5,0,2,4,-1};
        //expected largest descent: 5-(-1) = 6
        qWarning() << largest_descent.findLargestDescent(nums_three) << largest_descent.findLargestDescentAnotherWay(nums_three) << largest_descent.findLargestDescentBruteForce(nums_three);


        std::vector<int> nums_four{0,1,2,3,4,3,5,0,2,4,2};
        //expected largest descent: 5-(0) = 5
        qWarning() << largest_descent.findLargestDescent(nums_four) << largest_descent.findLargestDescentAnotherWay(nums_four) << largest_descent.findLargestDescentBruteForce(nums_four);
    }
}
