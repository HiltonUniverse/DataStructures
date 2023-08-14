#pragma once

#include <QDebug>
#include <unordered_map>

class MinimumWindowSubstring
{
public:
    std::string minWindow(const std::string& s,const std::string& t)
    {
        if(t.size() > s.size())
        {
            return "";
        }

        std::unordered_map<char, int> t_map;
        for(const char& c: t)
        {
            t_map[c]++;
        }

        int l = 0;
        int r = 0;

        int count = t.size();
        int min = 0;
        int max = INT_MAX;

        while(r < s.size())
        {
            //when we reach char count of 0 for a char, that means all the required char for that element is now in our
            //sliding window. Hence we don't need to keep it's count so we decrease count.
            if(t_map[s[r]] > 0)
            {
                --count;
            }

            //we decrement char count as we increase our window to the right
            t_map[s[r]]--;

            ++r;

            //if all char are in the our window, count will be 0
            while(count == 0)
            {
                //we keep track of the sliding window that contains all our required chars
                //if a new minimum window is found later on, we will replace the min and max.
                if( r - l < max)
                {
                    min = l;
                    max = r - l;
                }

                //now we shrink the window from the right to see if we can find a smaller window
                //As we decremented when adding char to our window, we will increment when we remove them from our window
                t_map[s[l]]++;
                if(t_map[s[l]] > 0)
                {
                    ++count;
                }

                ++l;
            }
        }


        //if max didn't change, that means we didn't find any minimum window size that contains t.
        if(max != INT_MAX)
        {
            return s.substr(min, max);
        }

        return "";
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void minimumWindowSubstringTest()
    {
        MinimumWindowSubstring substring;
        qWarning() << QString::fromStdString(substring.minWindow("ADOBECODEBANC", "ABC"));
        qWarning() << QString::fromStdString(substring.minWindow("a", "a"));
        qWarning() << QString::fromStdString(substring.minWindow("aa", "aa"));
        qWarning() << QString::fromStdString(substring.minWindow("cabwefgewcwaefgcf", "cae")); //expected cwae
    }
}
