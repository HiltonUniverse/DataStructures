#pragma once

#include <QDebug>

class FibonacciNumber
{
public:
    /*
     * A Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones,
     * usually starting with 0 and 1. In mathematical terms, the Fibonacci sequence is defined by the recurrence relation:
        F(0) = 0
        F(1) = 1
        F(n) = F(n-1) + F(n-2) for n > 1

        So, the Fibonacci sequence starts as follows: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, and so on.
     */


    //Time complexity - O(2^n) = branches^levels ( cracking the coding interview )
    //Space complexity - O(n) - the function call stack size
    int fib(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        else if( n == 1 )
        {
            return 1;
        }
        else
        {
            return fib(n-1) + fib(n-2);
        }
    }


    //-----------------------------------
    //Time complexity: O(n) - we have droped the time complexity to O(n) from exponential
    //Space complexity: O(1) - no stack used like we have for recursive call
    int fibImproved(int n)
    {
        if(n < 2)
        {
            return n;
        }

        int a = 0;
        int b = 1;
        int c = 0;

        for(int i = 1; i < n; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};


namespace test
{
    void fibonacciNumberTests()
    {
        FibonacciNumber fib_nan;
        qWarning() << fib_nan.fib(2) << fib_nan.fibImproved(5) << fib_nan.fibImproved(1);
    }
}
