#include <QDebug>
#include <vector>
#include <iostream>

#include <unordered_map>

class Solution
{
public:
    /*
    Overall time complexity: O(m*n)
    O(m) * (O(n) + O(1)) + O(m) * O(1)
    O(m*n) + O(m) + O(m)
    removing least significat terms and keeping the most significant term : O(m*n)


    Overall space complexity: O(m*n)

    1. unordered_map<string, vector<string>> m:
        The unordered_map m stores the key-value pairs for grouping the anagrams.
        The space it occupies depends on the number of distinct keys and the number of anagrams associated with each key.
        In the worst case, there can be 'n' distinct keys (where 'n' is the number of strings in strs),
        and each key might have 'm' anagrams (the maximum number of anagrams). Therefore, the worst-case space complexity for m is O(n * m).

    2.vector<vector<string>> result:
        The result vector stores the grouped anagrams as the final output.
        In the worst case, there can be 'n' groups (where 'n' is the number of strings in strs),
        and each group might contain all the strings if all strings are anagrams of each other.
        Therefore, the worst-case space complexity for result is O(n).

    3. vector<int> count(26) and string key (inside the getKey function):
        The count vector is used for counting character occurrences, and key is a string used as a hash key.
        Both count and key have fixed sizes and do not depend on the input size. They take constant space.
        The space complexity for count and key is O(1).

    Summing up the space complexities of all the components:

    O(n * m) (for unordered_map m) + O(n) (for vector<vector<string>> result) + O(1) (for vector<int> count(26) and string key) = O(n * m)

    In summary, the space complexity of the groupAnagrams function is O(n * m), where 'n' is the number of strings in the input strs,
    and 'm' is the maximum number of anagrams associated with a single key.
    The space complexity is primarily determined by the unordered_map m, which stores the grouped anagrams.*/

    std::vector<std::vector<QString>> groupAnagrams(const std::vector<QString>& strs)
    {
        std::unordered_map<QString, std::vector<QString>> comp;
        for(size_t i = 0; i < strs.size(); ++i) //let size of str = m = O(m)
        {
            QString key = getKey(strs[i]); // as deduced: O(n)
            comp[key].push_back(strs[i]); // O(1)
        }

        std::vector<std::vector<QString>> return_val;
        for(auto& [_,val] : comp) //O(m)
        {
            return_val.push_back(val); // O(1)
        }

        return return_val;
    }

private:
    QString getKey(const QString& str) // T = O(n) * O(1) + O(26) * O(1) = removing constants leaves us with complexity of: O(n)
    {
        std::vector<int> count(26);
        for(int i = 0; i < str.size(); ++i) //O(n)
        {
            count[str[i].unicode() - QString('a').unicode()->unicode()]++; //vector random access and value update = O(1)
        }

        QString key;
        for(const int& val : count) //O(26) = as we have 26 characters
        {
            key.append(QString::number(val)); //O(1) = adding elements to the end has constant time complexity unless reallocation is required then is O(n)
        }

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

        auto result =solution.groupAnagrams(strs);

        // expected to see:
        //Anagrams :  std::vector("hilton", "hiltno")
        //Anagrams :  std::vector("bat")
        //Anagrams :  std::vector("tan", "nat");
        //Anagrams :  std::vector("eat", "tea", "ate")

        for(const auto& res : result)
        {
            qWarning() << "Anagrams : " << res;
        }
    }
}
