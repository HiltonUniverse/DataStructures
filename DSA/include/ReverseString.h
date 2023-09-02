#pragma once

#include <QDebug>

class ReverseString
{
public:
    //Time complexity: O(n)
    //Space complexity: O(1)
    void reverseString(std::vector<char>& s)
    {
        int left = 0;
        int right = s.size() - 1;

        while(left < right)
        {
            std::swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};


namespace test
{
    void ReverseStringTests()
    {
        ReverseString reverse;
        std::vector<char> s{'h','e','l','l','o'};
        reverse.reverseString(s);
        qWarning() << s; //expected [o l l e h]
    }
}
