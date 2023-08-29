#pragma once

#include <QDebug>

class KokoEatingBanana
{
public:
    //Time complexity : O(n log n)
        //Input constraint is: 1 <= piles.length <= 10^4. As per this upper limit 10^4, we can safely run this on O(n log n) complexity.
    int minEatingSpeed(std::vector<int>& piles, int h)
    {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end()); //O(n)

        int result = right;

        //O(n log n)
        while(left <= right) //O(log n)
        {
            int banana_per_hr = left + (right - left)/2;
            //long int to handle inputs numbers larger than int
            long int total_of_hr_per_pile = 0;
            for(int p : piles) //O(n)
            {
                //cast either denominator or numerator to double so the result of their division becomes a double as well
                //and std::ceil can do it's magic. If p = 7 and banana_per_hr = 3.
                //integer division gives: 7/3 = 2 and std::ceil(2) = 2!
                //But with double cast: 7/3 = 2.33 and std::ceil(2.33) = 3 (Good)
                total_of_hr_per_pile += std::ceil(static_cast<double>(p)/banana_per_hr);
            }

            if(total_of_hr_per_pile > h)
            {
                left = banana_per_hr + 1;
            }
            else if(total_of_hr_per_pile <= h)
            {
                result = std::min(result, banana_per_hr);
                right = banana_per_hr - 1;
            }
        }

        return result;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void kokoEatingBananaTests()
    {
        KokoEatingBanana koko;
        std::vector<int> pile{3,6,7,11};
        //qWarning() << koko.minEatingSpeed(pile, 8);
        std::vector<int> pile_2{30,11,23,4,20};
        qWarning() << koko.minEatingSpeed(pile_2, 5);
        std::vector<int> pile_3{312884470};
        qWarning() << koko.minEatingSpeed(pile_3, 968709470);
    }
}
