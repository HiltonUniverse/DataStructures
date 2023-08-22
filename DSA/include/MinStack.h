#pragma once

#include <QDebug>

class MinStack
{
    //Time complexity: O(1) for each function
    //Space complexity: O(n)
public:
    MinStack() = default;

    void push(int val)
    {
        if(min_elem.empty())
        {
            min_elem.push_back(val);
        }
        else if(val <= min_elem.back())
        {
            min_elem.push_back(val); // new min element
        }

        stack.push_back(val);
    }

    void pop()
    {
        if(!min_elem.empty() && stack.back() == min_elem.back())
        {
            min_elem.pop_back();
        }

        stack.pop_back();
    }

    int top()
    {
        return stack.back();
    }

    int getMin()
    {
        return min_elem.back();
    }

private:
    std::vector<int> min_elem;
    std::vector<int> stack;
};

namespace test
{
    void minStackTests()
    {
        MinStack* minStack = new MinStack();
        minStack->push(-2);
        minStack->push(0);
        minStack->push(-3);
        minStack->push(-3);
        minStack->push(-3);
        qWarning() << minStack->getMin(); // return -3
        minStack->pop();
        qWarning() << minStack->top();    // return 0
        qWarning() << minStack->getMin(); // return -2
    }
}
