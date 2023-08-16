#pragma once

#include <QDebug>
#include <deque>

class FindGreatestCommonDivisorOfArray
{
public:
    int findGCD(const std::vector<int>& nums)
    {
        //find max min
        int max = 0;
        int min = INT_MAX; //this cannot be smaller than the elements that exist in the nums array

        for(const int n : nums) //O(n)
        {
            max = std::max(max, n);
            min = std::min(min, n);
        }

        return gcd(max, min);
    }

    int gcd(int a, int b)
    {
        if(b == 0) return a;
        return gcd(b, a%b);
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void findGreatestCommonDivisorOfArrayTests()
    {
        FindGreatestCommonDivisorOfArray gcd;
        qWarning() << gcd.findGCD({2,5,6,9,10});
    }
}
