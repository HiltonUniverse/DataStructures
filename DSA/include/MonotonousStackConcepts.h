#pragma once

#include <QDebug>
#include <stack>

//https://leetcode.com/discuss/study-guide/2347639/A-comprehensive-guide-and-template-for-monotonic-stack-based-problems

class MonotonousStacksCocepts
{
public:
    //T = O(n)
    //S = O(n)
    //We try and keep a monotonous decreasing stack.
    std::vector<int> findNextGreaterIndexes(std::vector<int>& heights)
    {
        //keeps track of next greater indexes
        std::stack<int> stack;

        std::vector<int> result(heights.size(), -1);
        for(int i = 0; i < heights.size(); ++i)
        {
            //If the top of stack is smaller than the current item of heights
            //that means we have to pop the stack.top to maintain a decreasing order.
            while(!stack.empty() && heights[stack.top()] < heights[i])
            {
                int index = stack.top();
                //for element at stack.top(), the next greatest index is i
                //as stack.top() element is < i element
                result[index] = i;
                stack.pop();
            }

            stack.push(i);
        }

        return result;
    }

    //-----------------------------------
    //Time and Space complexity: O(n)
    std::vector<int> findPreviousGreaterIndexes(std::vector<int>& heights)
    {
        std::stack<int> stack;
        std::vector<int> result(heights.size(), -1);

        for(int i = 0; i < heights.size(); ++i)
        {
            while(!stack.empty() && heights[stack.top()] <= heights[i])
            {
                stack.pop();
            }

            if(!stack.empty())
            {
                result[i] = stack.top();
            }

            stack.push(i);
        }

        return result;
    }

    //-----------------------------------
    //Time and space complexity : O(n)
    std::pair<std::vector<int>, std::vector<int>> findNextAndPreviousGreaterIndexes(std::vector<int>& heights)
    {
        std::stack<int> stack;

        std::vector<int> next_greater(heights.size(), -1);
        std::vector<int> previous_greater(heights.size(), -1);

        for(int i = 0; i < heights.size(); ++i)
        {
            while(!stack.empty() &&  heights[stack.top()] <= heights[i])
            {
                int stack_top_element_index = stack.top();

                //next greater element
                next_greater[stack_top_element_index] = i;
                stack.pop();
            }

            if(!stack.empty())
            {
                //previous greater element
                previous_greater[i] = stack.top();
            }

            stack.push(i);
        }

        return {next_greater, previous_greater};
    }




    //FIND NEXT AND PREVIOUS SMALLER INDEXES
    //Time and space complexity : O(n)
    //-----------------------------------
    std::vector<int> findNextSmallerIndexes(std::vector<int>& heights)
    {
        std::stack<int> stack;

        std::vector<int> result(heights.size(), -1);

        for(int i = 0; i < heights.size(); ++i)
        {
            while(!stack.empty() && heights[stack.top()] > heights[i])
            {
                int index = stack.top();
                result[index] = i;
                stack.pop();
            }

            stack.push(i);
        }

        return result;
    }

    //-----------------------------------
    //Time and space complexity : O(n)
    std::vector<int> findPreviousSmallerIndexes(std::vector<int>& heights)
    {
        std::stack<int> stack;

        std::vector<int> previous_smaller_index(heights.size(), -1);
        for(int i = 0; i < heights.size(); ++i)
        {
            while(!stack.empty() && heights[stack.top()] >= heights[i])
            {
                stack.pop();
            }

            if(!stack.empty())
            {
                previous_smaller_index[i] = stack.top();
            }

            stack.push(i);
        }

        return previous_smaller_index;
    }

    //-----------------------------------
    //Time and space complexity : O(n)
    std::pair<std::vector<int>, std::vector<int>> findPreviousAndNextSmallerIndexes(std::vector<int>& heights)
    {
        std::stack<int> stack;

        std::vector<int> next_smaller_element(heights.size(), -1);
        std::vector<int> previous_smaller_element(heights.size(), -1);

        for(int i = 0; i < heights.size(); ++i)
        {
            while(!stack.empty() && heights[stack.top()] >= heights[i])
            {
                //next smaller indexes
                int index = stack.top();
                next_smaller_element[index] = i;
                stack.pop();
            }

            if(!stack.empty())
            {
                previous_smaller_element[i] = stack.top();
            }

            stack.push(i);
        }
        return {next_smaller_element, previous_smaller_element};
    }
};

namespace test
{
    void findNextAndPreviousGreaterIndexesTests()
    {
        MonotonousStacksCocepts concepts;
        std::vector<int> heights{13, 8, 1, 5, 2, 5, 9, 7, 6, 12};
        qWarning() << (concepts.findNextGreaterIndexes(heights) == std::vector{-1, 6, 3, 6, 5, 6, 9, 9, 9, -1});

        qWarning() << (concepts.findPreviousGreaterIndexes(heights) == std::vector{-1, 0, 1, 1, 3, 1, 0, 6, 7, 0});

        qWarning() << (concepts.findNextAndPreviousGreaterIndexes(heights) == std::pair(std::vector{-1, 6, 3, 5, 5, 6, 9, 9, 9, -1}, std::vector{-1, 0, 1, 1, 3, 1, 0, 6, 7, 0}));
    }

    void findNextAndPreviousSmallerIndexesTests()
    {
        MonotonousStacksCocepts concepts;
        std::vector<int> heights{13, 8, 1, 5, 2, 5, 9, 7, 6, 12};
        qWarning() << concepts.findNextSmallerIndexes(heights); //expected output: {1, 2, -1, 4, -1, -1, 7, 8, -1, -1}
        qWarning() << concepts.findPreviousSmallerIndexes(heights); // expected output:{-1, -1, -1, 2, 2, 4, 5, 5, 5, 8}
        //expected output: std::pair(std::vector(1, 2, -1, 4, -1, -1, 7, 8, -1, -1),std::vector(-1, -1, -1, 2, 2, 4, 5, 5, 5, 8))
        qWarning() << concepts.findPreviousAndNextSmallerIndexes(heights);
    }
}

//Some of the popular challanges we can solve using these methods are
// 503: Next Greater Element II
// 739: Daily Temperatures
// 1762: Buildings with an ocean view
// 456: Find 132 Pattern
// 42: Trapping rain water
// 84: Largest rectangle in histogram
// 1944: Number of visible people in the queue

//For more challanges we have: https://leetcode.com/tag/monotonic-stack/
