#pragma once

#include <QDebug>
#include <unordered_map>

class PermutationInString
{
public:
    /*
     * Time complexity  : O(n)
     * Space complexity : O(26) + O(26) = O(1)
     */
    bool checkInclusion(std::string s1, std::string s2)
    {
        if(s1.size() > s2.size())
        {
            return false;
        }

        std::vector<int> s1_frequency(26, 0);
        std::vector<int> s2_frequency(26, 0);
        for(int i = 0; i < s1.size(); ++i)
        {
            s1_frequency[s1[i] - 'a']++;
            s2_frequency[s2[i] - 'a']++;
        }

        int l = 0;
        int r = s1.size() - 1;

        while(r < s2.size())
        {
            if(s1_frequency == s2_frequency)
            {
                return true;
            }

            s2_frequency[s2[l] - 'a']--;
            ++l;

            ++r;
            //check we are still in range
            if(r < s2.size())
            {
                s2_frequency[s2[r] - 'a']++;
            }
        }

        return false;
    }


    //-----------------------------------
    bool checkInclusionNoComparision(std::string s1, std::string s2)
    {
        int m = s1.size();
        int n = s2.size();
        if (m > n) {
            return false;
        }

        std::vector<int> count(26);
        for (int i = 0; i < m; i++)
        {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if (isPermutation(count))
        {
            return true;
        }

        for (int i = m; i < n; i++)
        {
            count[s2[i] - 'a']--;
            count[s2[i - m] - 'a']++;
            if (isPermutation(count))
            {
                return true;
            }
        }

        return false;
    }

private:
    bool isPermutation(std::vector<int>& count)
    {
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
void permutationInStringTest()
{
    PermutationInString permutation;
    qWarning() << permutation.checkInclusionNoComparision("ab", "eidbaooo");

    qWarning() << permutation.checkInclusion("ab", "eidboaoo");
}
}
