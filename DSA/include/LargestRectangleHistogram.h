#pragma once

#include <QDebug>
#include <stack>

class LargestRectangleHistogram
{
public:
    //For each index in the histogram, we find what is the previous and next smallest
    int largestRectangleArea(std::vector<int>& heights)
    {
        std::stack<int> stack;

        std::vector<int> next_smallest_index(heights.size(), heights.size());
        std::vector<int> previous_smallest_index(heights.size(), -1);
        for(int i = 0; i < heights.size(); ++i)
        {
            while(!stack.empty() && heights[stack.top()] > heights[i])
            {
                int index = stack.top();
                next_smallest_index[index] = i;
                stack.pop();
            }

            if(!stack.empty())
            {
                previous_smallest_index[i] = stack.top();
            }

            stack.push(i);
        }

        int max_area = 0;
        for(int i = 0; i < heights.size(); ++i)
        {
            int width = next_smallest_index[i] - previous_smallest_index[i] - 1;
            int height = heights[i];
            max_area = std::max(max_area, width*height);
        }

        return max_area;
    }
};


namespace test
{
    void largestRectangleHistogramTests()
    {
        LargestRectangleHistogram largest;
        std::vector<int> heights{2,1,5,6,2,3};
        qWarning() << largest.largestRectangleArea(heights);

        std::vector<int> heights_2{2,4};
        qWarning() << largest.largestRectangleArea(heights_2);
    }
}
