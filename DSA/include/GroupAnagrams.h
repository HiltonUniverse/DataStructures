#include <QDebug>
#include <vector>
#include <iostream>

#include <unordered_map>

class Solution
{
public:

    //Time complexity : O(n * s log s)
        //n = number of strings
        //s = length of each string
    std::vector<std::vector<QString>> groupAnagramsLogComplexity(std::vector<QString>& strs)
    {
        std::unordered_map<QString, std::vector<QString>> result;

        //O(n * s log s)
        for(auto str : strs) //O(n)
        {
            QString before_sort = str;
            std::sort(str.begin(), str.end()); //O(s log s) = overallsorting takes
            result[str].push_back(before_sort);
        }

        std::vector<std::vector<QString>> final_result;
        for(const auto &[key, value] : result)
        {
            final_result.push_back(value);
        }

        return final_result;
    }


    //Time complexity: O(v*s) + O(v) = O(v*s)
    //Space complexity: O(v * s) = worst case for each string we could have a vector
    std::vector<std::vector<QString>> groupAnagrams(const std::vector<QString>& strs)
    {
        std::unordered_map<QString, std::vector<QString>> pairs;//O(s * v) = for each string we could have a vector
        //v = vector length
        //O(v) * O(s) = O(v * s)
        for(auto val : strs) //O(v)
        {
            QString key = generateKey(val); //O(s)
            pairs[key].push_back(val); //O(1)
        }

        std::vector<std::vector<QString>> result;
        for(auto& [key, value] : pairs) //O(v) = worst case all strs are unique
        {
            result.push_back(value);
        }

        return result;
    }

    //-----------------------------------
    // s = str length
    //O(s) + O(26) = O(s)
    QString generateKey(QString& str)
    {
        std::vector<int> count(26);

        for(char c : str.toStdString()) //O(s)
        {
            count[c - 'a']++;
        }

        QString key;
        for(int a : count)//O(26)
        {
            //This # addition is very important
            //after we reach the count of 10 for a character, eg: b= 1, d= 10 and b=10, c = 1
            //we will have key for b1 and d10: 01010
            //and for b10 and c1             : 01010
            //Now even thought they are not the same in count vector, they will be the same when convert to QString.
            //so we add a # to make them look distinct.
            // 0#1#0#10#
            // 0#10#1#0#
            key.append(QString::number(a) + "#");
        }
        qWarning() << key;
        return key;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void testGroupAnagram()
    {
        //input data
        std::vector<QString> strs{"eat","tea","tan","ate","nat","bat","hilton","hiltno"};
        Solution solution;

        //auto result =solution.groupAnagrams(strs);

        /*// expected to see:
        //Anagrams :  std::vector("hilton", "hiltno")
        //Anagrams :  std::vector("bat")
        //Anagrams :  std::vector("tan", "nat");
        //Anagrams :  std::vector("eat", "tea", "ate")

        for(const auto& res : result)
        {
            qWarning() << "Anagrams : " << res;
        }*/

        std::vector<QString> new_strs{"bdddddddddd","bbbbbbbbbbc"};
        auto result = solution.groupAnagrams(new_strs);

        for(const auto& res : result)
        {
            qWarning() << "Anagrams : " << res;
        }
    }
}
