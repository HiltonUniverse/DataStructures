#pragma once

#include <QDebug>
#include <unordered_set>

class LongestSubstringWithoutRepeatingCharacters
{
public:
    /*
     * Sliding window to reduce Time complexity
     * Time complexity  : O(n)
     * Space complexity : O(n)
     */
    int lengthOfLongestSubstring(std::string& s)
    {
        std::unordered_set<char> substringChar;
        int l = 0;
        int max_length = 0;

        for(int i = 0 ; i < s.size(); ++i)
        {
            while(substringChar.count(s[i]))
            {
                substringChar.erase(s[l]);
                ++l;
            }
            substringChar.insert(s[i]);
            max_length = std::max( max_length,i - l + 1 );
        }

        return max_length;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void lengthOfLongestSubstringTest()
    {
        LongestSubstringWithoutRepeatingCharacters substring;
        std::string s{"abcabcbb"};
        qWarning() << substring.lengthOfLongestSubstring(s);

        std::string s_two{"bbbbb"};
        qWarning() << substring.lengthOfLongestSubstring(s_two);

        std::string s_three{"pwwkew"};
        qWarning() << substring.lengthOfLongestSubstring(s_three);
    }
}
