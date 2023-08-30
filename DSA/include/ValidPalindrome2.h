#include <QDebug>


class ValidPalindromeII
{
public:
    //-----------------------------------
    bool isValidPalindrome(int left, int right, const std::string& s, int count)
    {
        if(count > 1)
        {
            return false;
        }

        while(left < right)
        {
            if(s[left] == s[right])
            {
                ++left;
                --right;
                continue;
            }
            else
            {
                return isValidPalindrome(left + 1, right, s, count + 1) || isValidPalindrome(left, right - 1, s, count + 1);
            }
        }

        return true;
    }

    //-----------------------------------
    bool validPalindrome(std::string s)
    {
        int left = 0;
        int right = s.length() - 1;
        int count = 0;

        return isValidPalindrome(left, right, s, count);
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void validPalindromeIITest()
    {
        ValidPalindromeII valid_palindrome;

        std::string str = {"cbbcc"};
        qWarning() << valid_palindrome.validPalindrome(str);

        std::string str_2 = {"aba"};
        qWarning() << valid_palindrome.validPalindrome(str_2);

        std::string str_3 = {"abca"};
        qWarning() << valid_palindrome.validPalindrome(str_3);

        std::string str_4 = {"abdca"};
        qWarning() << valid_palindrome.validPalindrome(str_4);
    }
}
