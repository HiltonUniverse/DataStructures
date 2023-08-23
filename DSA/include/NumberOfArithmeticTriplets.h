#pragma once

#include <QDebug>

class NumberOfArithmeticTriplets
{
public:
    //Time complexity: O(n^2)
    //Space complexity: O(1)
    int arithmeticTriplets(const std::vector<int>& nums, int diff)
    {
        int count = 0;

        for(int i = 0; i < nums.size() - 2; ++i) //O(n - 2)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            bool found = false;

            while( l < r ) //O(n)
            {
                int first_triplets = nums[l] - nums[i];
                int second_triplets = nums[r] - nums[l];

                if(first_triplets == diff && second_triplets == diff)
                {
                    ++count;
                    ++l;
                    --r;
                }
                else if( first_triplets < diff )
                {
                    ++l;
                }
                else
                {
                    --r;
                }
            }

        }

        return count;
    }
};


namespace test
{
    void numberOfArithmeticTriplets()
    {
        NumberOfArithmeticTriplets nrarth;
        qWarning() << nrarth.arithmeticTriplets({0,1,4,6,7,10}, 3);
        qWarning() << nrarth.arithmeticTriplets({4,5,6,7,8,9}, 2);
        qWarning() << nrarth.arithmeticTriplets({1,5,6,9}, 4);
    }
}
