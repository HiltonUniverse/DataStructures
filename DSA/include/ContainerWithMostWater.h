#include <QDebug>


class ContainerWithMostWater
{
     /*
      * Time complexity  : O(n)
      * Space complexity : O(1)
      */
public:
    int maxArea(std::vector<int>& height)
    {
        int max_area = 0;
        int l = 0;
        int r = height.size() - 1;

        while(l < r)
        {
            //It seems instiantiating these variables also cost extra memory and speed.
            //Withouth these we have: 52ms and 59MB, but with these we have 78ms and 59.1MB
            //But readability is important than a little speed and memory improvement.
            const int abs_height = std::min(height[l], height[r]);
            const int width = r - l;
            const int area = abs_height * width;
            max_area = std::max(area, max_area);

            if(height[l] < height[r])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }

        return max_area;
    }

    //-----------------------------------
    //If input is a very large number, this will take forever to compute.
    //In leetcode it even reaches time limit excedded error. We need a liner time solution and not a quadratic time solution as this
    /*
     * Time complexity  : O(n^2)
     * Space complexity : O(1)
     */
    int maxAreaBruteForce(std::vector<int>& height)
    {
        int max_area = 0;
        for(int i = 0; i < height.size() - 1; ++i)
        {
            for(int j = i + 1 ; j < height.size(); ++j)
            {
                const int abs_height = std::min(height[i], height[j]);
                const int width = j - i;
                const int area = abs_height * width;
                max_area = std::max(area, max_area);
            }
        }

        return max_area;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void maxAreaTest()
    {
        ContainerWithMostWater most_water;
        std::vector<int> heights{1,8,6,2,5,4,8,3,7};
        qWarning() << most_water.maxArea(heights);

        std::vector<int> heights_sec{1,1};
        qWarning() << most_water.maxArea(heights_sec);
    }
}
