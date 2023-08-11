#include <QDebug>

class TrappingRainWater
{
public:
    /*
     * Time complexity  : O(n)
     * Space complexity : O(1)
     */
    int trapBetter(std::vector<int>& height)
    {
        int l = 0;
        int r = height.size() - 1;

        int max_left = height[l];
        int max_right = height[r];

        int area = 0;
        while(l < r)
        {
            if(max_left < max_right)
            {
                ++l;
                max_left = std::max(height[l], max_left);
                int temp_area = max_left - height[l];
                if(temp_area > 0)
                {
                    area += temp_area;
                }
            }
            else
            {
                --r;
                max_right = std::max(height[r], max_right);
                int temp_area = max_right - height[r];
                if(temp_area > 0)
                {
                    area += temp_area;
                }
            }
        }

        return area;
    }

    /*
     * Time complexity  : O(n)
     * Space complexity : O(n)
     */
    int trap(std::vector<int>& height)
    {
        //find max left heights
        std::vector<int> max_left_heights;
        int max_left = 0;
        max_left_heights.push_back(max_left);

        for(int i = 1 ; i < height.size(); ++i)
        {
            max_left = std::max(max_left, height[i - 1]);
            max_left_heights.push_back(max_left);
        }

        //find max right heights
        std::vector<int> max_right_heights(height.size(), 0);
        int max_right = 0;
        max_right_heights[height.size() - 1] = max_right;

        for(int i = height.size() - 2 ; i >= 0; --i)
        {
            max_right = std::max(max_right, height[i + 1]);
            max_right_heights[i] = max_right;
        }

        //find area
        int area = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            int bottleneck_height = std::min(max_right_heights[i], max_left_heights[i]);
            int temp_area = bottleneck_height - height[i];
            if(temp_area > 0)
            {
                area += temp_area;
            }
        }

        return area;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void trappingRainWaterTest()
    {
        TrappingRainWater trap_rain_water;
        std::vector<int> heights{0,1,0,2,1,0,1,3,2,1,2,1};
        qWarning() << trap_rain_water.trapBetter(heights);
    }
}
