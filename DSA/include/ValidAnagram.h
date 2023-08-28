#include <QDebug>

#include <unordered_map>

class ValidAnagram
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        if(s.length() != t.length())
        {
            return false;
        }

        std::unordered_map<char, int> char_count;
        for(char c : s)
        {
            char_count[c]++;
        }

        for(char c : t)
        {
            char_count[c]--;
        }

        for(auto [key,value] : char_count)
        {
            if(value != 0)
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
    void validAnagramTests()
    {
        ValidAnagram anagram;

        qWarning() << anagram.isAnagram("anagram", "nagaram");
    }
}
