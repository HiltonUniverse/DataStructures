#include <QDebug>


class TwoSum2InputArrayIsSorted
{
     /*
      * Time complexity : O(n)
      * Space complexity: O(1)
      */
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        int l = 0;
        int r = numbers.size() - 1;

        while(l < r)
        {
            int calc = numbers[l] + numbers[r];
            //Note: if we just do:
            //if(calc == target)
            //if(calc > target)
            //if(calc < target)

            //instead of
            //if(calc == target)
            //else if(calc > target)
            //else if(calc < target)

            //then every time if is ran, more memory is used internally. (15.7MB), 8.9% faster than most
            //But after using if, else if, the memory beams: ()15.5MB) and 94.08% faster than most
            if(calc == target)
            {
                return {l + 1, r + 1};
            }
            else if(calc > target)
            {
                --r;
            }
            else if(calc < target)
            {
                ++l;
            }
        }

        return {};
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void twoSum2InputArrayIsSortedTest()
    {
        TwoSum2InputArrayIsSorted two_sum;
        std::vector<int> numbers{2,7,11,15};
        qWarning() << (two_sum.twoSum(numbers, 9) == std::vector<int>{1,2});

        std::vector<int> numbers_two{2,3,4};
        qWarning() << (two_sum.twoSum(numbers_two, 6) == std::vector<int>{1,3});

        std::vector<int> numbers_three{-1,0};
        qWarning() << (two_sum.twoSum(numbers_three, -1) == std::vector<int>{1,2});
    }
}
