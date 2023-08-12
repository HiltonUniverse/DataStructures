#pragma once

#include <QDebug>

class BestTimetoBuyandSellStock
{
public:
    /*
     * Sliding window to reduce Time complexity
     * Time complexity  : O(n)
     * Space complexity : O(1)
     */
    int maxProfit(std::vector<int>& prices)
    {
        int l = 0;
        int r = 1;

        int max_profit = 0;

        while(r < prices.size())
        {
            if(prices[l] < prices[r])
            {
                int profit = prices[r] - prices[l];
                max_profit = std::max(profit, max_profit);
            }
            else
            {
                l = r;
            }
            ++r;
        }

        return max_profit;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void bestTimetoBuyandSellStockTest()
    {
        BestTimetoBuyandSellStock sell_buy;
        //At the end, left ptr will be == right ptr as -1 is lower than 1. But that does not matter
        std::vector<int> prices{7,1,5,3,6,4,-1};
        //expected output: 6-1 = 5
        qWarning() << sell_buy.maxProfit(prices);


        std::vector<int> prices_two{7,6,4,3,1};
        //expected output: 0
        qWarning() << sell_buy.maxProfit(prices_two);

        std::vector<int> prices_three{2,4,1};
        //expected output: 2
        qWarning() << sell_buy.maxProfit(prices_three);
    }
}
