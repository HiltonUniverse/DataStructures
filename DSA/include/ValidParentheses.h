#pragma once

#include <QDebug>
#include <unordered_map>
#include <stack>

class ValidParentheses
{
public:
    //Time complexity : O(n)
    //Space complexity: O(n)
    bool isValid(std::string& s)
    {
        std::unordered_map<char, char> combination{{'}','{'},
                                                   {')','('},
                                                   {']','['}};

        std::stack<char> tracker;

        for(const char c : s)
        {
            if(combination.count(c))
            {
                if(tracker.empty())
                {
                    return false;
                }

                if(combination[c] != tracker.top())
                {
                    return false;
                }

                tracker.pop();
            }
            else
            {
                tracker.push(c);
            }
        }

        return tracker.empty();
    }
};


namespace test
{
    void validParenthesisTests()
    {
        ValidParentheses valid;
        std::string input = "([]{})";
        qWarning() << valid.isValid(input); //expected true

        std::string input_second = "()";
        qWarning() << valid.isValid(input_second); //expected true

        std::string input_third = "()[]{}";
        qWarning() << valid.isValid(input_third); //expected true

        std::string input_fourth = "(]";
        qWarning() << valid.isValid(input_fourth); //expected false

        std::string input_five = "[";
        qWarning() << valid.isValid(input_five); //expected false

        std::string input_six = "){";
        qWarning() << valid.isValid(input_six); //expected false
    }
}
