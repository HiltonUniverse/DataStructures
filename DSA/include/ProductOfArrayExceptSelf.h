#pragma once

#include <QDebug>
#include <vector>
#include <iostream>

#include <unordered_map>
#include <queue>

class ProductOfArrayExceptSelf
{
public:
    //Time complexity = O(n^2)
    //Space complexity = O(1)
    std::vector<int> bruteForceProductExceptSelf(std::vector<int>& nums)
    {
        std::vector<int> result;
        for(size_t i = 0 ; i < nums.size(); ++i)
        {
            int product = 1;
            for(size_t j = 0 ; j < nums.size(); ++j)
            {
                if(i == j)
                {
                    continue;
                }

                product *= nums[j];
            }
            result.push_back(product);
        }

        return result;
    }

    //Time complexity = O(n)
    //Space complexity = O(n)
    std::vector<int> secondBestProductExceptSelf(std::vector<int>& nums)
    {
        size_t n = nums.size();
        std::vector<int> result(n, 1);
        std::vector<int> left_product(n, 1);
        std::vector<int> right_product(n, 1);

        int product = 1;
        for(size_t i = 0 ; i < n; ++i)
        {
            product *= nums[i];
            left_product[i] = product;
        }

        product = 1;
        //Note: using size_t i when we decrement i has a potential issue. The issue is with i >= 0.
        //The loop runs until i is greater or equal to 0.
        //But the next loop we do --i after i reaches 0 gives i = -1, the next loop will execute indefinately.
        //This is beacuse size_t is unsigned int and i = -1 is implicitly casted to size_t giving
        //a very large positive number. Hence this loop will run indefinately.
        for(int i = n-1 ; i >= 0; --i)
        {
            product *= nums[i];
            right_product[i] = product;
        }

        for(size_t i = 0; i < n; ++i)
        {
            if(i == 0)
            {
                result[i] = right_product[i+1];
            }
            else if(i == n-1)
            {
                result[i] = left_product[i-1];
            }
            else
            {
                result[i] = left_product[i-1] * right_product[i+1];
            }
        }

        return result;
    }

    //Time complexity = O(n)
    //Space complexity = O(1)
    std::vector<int> bestProductExceptSelf(std::vector<int>& nums)
    {
        int n = nums.size();
        std::vector<int> result(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; i++)
        {
            result[i] = prefix;
            prefix = prefix * nums[i];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            result[i] = postfix * result[i];
            postfix *= nums[i];
        }

        return result;
    }

};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    //-----------------------------------
    void bruteForceProductExceptSelfTest()
    {
        ProductOfArrayExceptSelf product;

        std::vector<int> nums{1,2,3,4};
        auto result = product.bruteForceProductExceptSelf(nums);
        std::vector<int> expected{24, 12, 8, 6};
        qWarning() << result << (result == expected);

        std::vector<int> nums_2{-1,1,0,-3,3};
        auto result_2 = product.bruteForceProductExceptSelf(nums_2);
        std::vector<int> expected_2{0, 0, 9, 0, 0};
        qWarning() << result_2 << (result_2 == expected_2);

        //If we have an nums_2 vector with excepetionally large input, this brute force methode won't work!
        //This is because it has O(n^2) time complexity.
    }

    //-----------------------------------
    void secondBestProductExceptSelfTest()
    {
        ProductOfArrayExceptSelf product;

        std::vector<int> nums{1,2,3,4};
        auto result = product.secondBestProductExceptSelf(nums);
        std::vector<int> expected{24, 12, 8, 6};
        qWarning() << result << (result == expected);

        std::vector<int> nums_2{-1,1,0,-3,3};
        auto result_2 = product.secondBestProductExceptSelf(nums_2);
        std::vector<int> expected_2{0, 0, 9, 0, 0};
        qWarning() << result_2 << (result_2 == expected_2);
    }

    //-----------------------------------
    void bestProductExceptSelfTest()
    {
        ProductOfArrayExceptSelf product;

        std::vector<int> nums{1,2,3,4};
        auto result = product.bestProductExceptSelf(nums);
        std::vector<int> expected{24, 12, 8, 6};
        qWarning() << result << (result == expected);

        std::vector<int> nums_2{-1,1,0,-3,3};
        auto result_2 = product.bestProductExceptSelf(nums_2);
        std::vector<int> expected_2{0, 0, 9, 0, 0};
        qWarning() << result_2 << (result_2 == expected_2);
    }
}
