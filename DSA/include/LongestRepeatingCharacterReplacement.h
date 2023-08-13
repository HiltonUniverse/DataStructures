#pragma once

#include <QDebug>
#include <unordered_map>

class LongestRepeatingCharacterReplacement
{
public:
    /*
     * Time complexity  : O(n)
     * Space complexity : O(n)
     */
    int characterReplacement(std::string& s, int k)
    {
        std::unordered_map<char,int> char_count;
        for(const char& c : s)
        {
            char_count[c] = 0;
        }

        int l = 0;
        int r = 0;
        int result = 0;
        int max_count = 0;

        while(r < s.length())
        {
            char_count[s[r]]++;
            int window_size = r - l + 1;
            //if new char has higher count than what we have seen so far, we set that as the max count
            max_count = std::max(max_count, char_count[s[r]]);

            if(window_size - max_count <= k)
            {
                result = window_size;
            }
            else
            {
                char_count[s[l]]--;
                ++l;
            }

            ++r;
        }

        return result;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void characterReplacementTest()
    {
        LongestRepeatingCharacterReplacement replacement;
        std::string s{"ABAB"};
        qWarning() << replacement.characterReplacement(s, 2);

        std::string s_two{"AABABBA"};
        qWarning() << replacement.characterReplacement(s_two, 1);
    }
}
