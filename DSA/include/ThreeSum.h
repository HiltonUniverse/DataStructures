#include <QDebug>


class ThreeSum
{
     /*
      * Time complexity : O(n log n) + O(n^2) = O(n^2)
      * Space complexity: O(1)
      */
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> output;

        std::sort(nums.begin(), nums.end(), std::less<int>()); //O(n log n)

        for(int i = 0; i < nums.size(); ++i) //O(n)
        {
            int target = nums[i];

            if(i > 0 && target == nums[i-1])
            {
                //Prevent duplicated index finding, if we have two duplicate numbers they will return same 3 index so we skip.
                continue;
            }

            //we start from next element of target element, which is i+1
            int l = i+1;
            int r = nums.size() - 1;

            while(l < r) //O(n)
            {
                int calc = target + nums[l] + nums[r];
                if(calc < 0)
                {
                    ++l;
                }
                else if(calc > 0)
                {
                    --r;
                }
                else
                {
                    output.push_back({target, nums[l], nums[r]});
                    //
                    while(l < r && nums[l] == nums[l+1])
                    {
                        ++l;
                    }
                    ++l;

                    while(l < r && nums[r] == nums[r -1])
                    {
                        --r;
                    }
                    --r;
                }
            }
        }
        return output;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void threeSumTest()
    {
        ThreeSum three_sum;

        std::vector<int> nums{-1,0,1,2,-1,-4};
        qWarning() << three_sum.threeSum(nums);

        std::vector<int> nums_two{0,1,1};
        qWarning() << three_sum.threeSum(nums_two);

        std::vector<int> nums_three{0,0,0};
        qWarning() << three_sum.threeSum(nums_three);

        std::vector<int> nums_failed{0,0,0, 0};
        qWarning() << three_sum.threeSum(nums_failed);

        std::vector<int> nums_failed_two{-1,0,1,0};
        qWarning() << three_sum.threeSum(nums_failed_two);
    }
}
