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
            //if new char has higher count than what we have seen so far, we set that as the max count
            //Why do we always take the max for max_count and not decrease it if the count int he char_count drops?
            //see video: https://youtu.be/gqXU1UyA8pk?t=748
            max_count = std::max(max_count, char_count[s[r]]);

            if(r - l + 1 - max_count > k)
            {
                char_count[s[l]]--;
                ++l;
            }

            result = std::max(result, r - l + 1);
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
        //qWarning() << replacement.characterReplacement(s, 2);

        std::string s_two{"AAABBA"};
        qWarning() << replacement.characterReplacement(s_two, 1);
    }
}
