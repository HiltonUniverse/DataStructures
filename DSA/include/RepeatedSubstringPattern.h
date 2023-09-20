#include <QDebug>

#include <unordered_map>

class RepeatedSubstringPattern
{
public:
    bool repeatedSubstringPattern(const std::string& s)
    {
        int l = 0;
        int r = 0;
        while( r < s.size()) //O(n)
        {
            int repeat_numbers = s.size()/(r-l+1);
            if(repeat_numbers == 1) // no point in iterating if the repeat number is greater than half the size of the input string
            {
                break;
            }

            QString to_repeat = QString::fromStdString(s.substr(l,r-l+1));
            QString result = "";
            for(int i = 0; i < repeat_numbers; ++i) //O(n-1)
            {
                result += to_repeat;
            }
            if(result == QString::fromStdString(s))
            {
                return true;
            }

            qWarning() << repeat_numbers << to_repeat << " " << r << " " << result;
            ++r;
        }

        return false;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void RepeatedSubstringPatternTests()
    {
        RepeatedSubstringPattern pattern;
        qWarning() << pattern.repeatedSubstringPattern("ababab");
        qWarning() << pattern.repeatedSubstringPattern("abc");
    }
}
