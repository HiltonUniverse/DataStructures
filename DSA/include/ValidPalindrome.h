#include <QDebug>


class ValidPalindrome
{
     /*
      * Time complexity : O(n)
      * Space complexity: O(n) because it could contain all the elemnts in the str
      */
public:
    bool isValidPalindrome(std::string& str)
    {
        std::string clean_string=""; //O(n)

        for(const auto& s : str) //O(n)
        {
            if(std::iswalnum(s)) //O(1)
            {
                clean_string += std::tolower(s); //O(1)
            }
        }

        if(clean_string.empty())
        {
            return true;
        }

        auto begin_iter = clean_string.begin();
        auto end_iter = clean_string.end() - 1;

       for(int i = 0 ; i < clean_string.size(); ++i) //O(n)
       {
           if(begin_iter == end_iter)
           {
               break;
           }

           if(*begin_iter == *end_iter)
           {
               ++begin_iter;
               --end_iter;
               continue;
           }

           return false;
       }

        return true;
    }

    //-----------------------------------
    /*
     * Time complexity : O(n)
     * Space complexity: O(1)
     */
    bool isValidPalindromeBetter(std::string& s)
    {
        int l = 0;
        int r = s.length() - 1;

        while( l < r)
        {
            while(!std::isalnum(s[l]) && l < r )
            {
                ++l;
            }

            while(!std::isalnum(s[r]) && l < r)
            {
                --r;
            }

            if(std::tolower(s[l]) != std::tolower(s[r]))
            {
                return false;
            }

            ++l;
            --r;
        }

        return true;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void validPalindromeTest()
    {
        ValidPalindrome valid_palindrome;

        std::string str = {"A man, a plan, a canal: Panama"};
        qWarning() << valid_palindrome.isValidPalindromeBetter(str);

        std::string str_two = {"race a car"};
        qWarning() << valid_palindrome.isValidPalindrome(str_two);

        std::string str_empty = {""};
        qWarning() << valid_palindrome.isValidPalindrome(str_empty);

        std::string failing_test = {"0P"};
        qWarning() << valid_palindrome.isValidPalindrome(failing_test);
    }
}
