#pragma once

#include <QDebug>

class PalindromeNumber
{
    //The complexity for all these are: O(n) = n is the number of digits for given string
public:
    bool isPalindrome(int x)
    {
        //if it's a negative number we already know it's not a palindrome
          //because in -121, -1 and 1 are not the same
          if( x < 0)
          {
              return false;
          }

          //long int because there are div that are larger than what
          //our int can hold in the tests.
          long int div = 1;
          // 10 * div to ensure we don't have for 121 a div of 1000.
          //That will happen, if we try it quickly on our paper.
          while(x >= 10 * div)
          {
              div *= 10;
          }

          while(x != 0)
          {
              int right = x % 10; //121, returns last 1
              int left = x/div; // 121, returns first 1

              if(right != left)
              {
                  return false;
              }

              //int chop_right = (x % div); //this is how we chop off the left part: 121 % div gives 21
              //int chop_left = chop_right/10; //this is how we chop off the right part: 21/10 = 2
              x = (x % div)/ 10;

              //then we reduce our div by 2 digits as we have chopped off 2 digits from x.
              div /= 100;
          }

          return true;
    }

    //-----------------------------------
    //here we reverse X and check if original x == reversed x.
    bool isPalindromeReverseX(int x)
    {
        //if it's a negative number we already know it's not a palindrome
        //because in -121, -1 and 1 are not the same
        if( x < 0)
        {
            return false;
        }

        long int sum = 0;
        int temp_x = x;
        while(temp_x != 0)
        {
            sum *= 10; //get sum to 10's place
            sum = sum + (temp_x % 10); //get last number and add to sum
            temp_x = temp_x/10; //remove the last number from x as it was already considered
        }

        return sum == x;
    }

    //-----------------------------------
    bool isPalindromeConvertToStringAndReverse(int x)
    {
        std::string rev = std::to_string(x);
        reverse(rev.begin(), rev.end()); //O(n/2) = O(n)
        return std::to_string(x) == rev;
    }

    //-----------------------------------
    bool isPalindromeConvertToStringAndTwoPointers(int x)
    {
        std::string s = std::to_string(x);
        int i = 0, j = s.size()-1;
        while (i <= j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }

        return true;
    }
};

namespace test
{
    void isPalindromeNumberTests()
    {
        PalindromeNumber palindrome;
        qWarning() << palindrome.isPalindrome(121);
        qWarning() << palindrome.isPalindrome(-121); //Negative numbers are never palindrome
        qWarning() << palindrome.isPalindrome(0); //A single digit is also considered a palindrome except negative numbers
        qWarning() << palindrome.isPalindrome(-1);
    }
}
