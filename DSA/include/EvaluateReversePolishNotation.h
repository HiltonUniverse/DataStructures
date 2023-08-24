#pragma once

#include <QDebug>

#include <stack>

class EvaluateReversePolishNotation
{
public:
    //Time complexity: O(n), we need to iterate over every token
    //Space complexity: O(n)
    int evalRPN(const std::vector<std::string>& tokens)
    {
        for(const std::string& token : tokens)
        {
            //we check if token.size() > 1 because only numbers will have size > 1.
            // Operators like +, -, * and / will always have size 1.
            //if we have a number of size 1, then isdigit will check if it's a number or not.
            if(token.size() > 1 || std::isdigit(token[0]))
            {
                result.push(std::stoi(token));
                continue;
            }

            int first = result.top();
            result.pop();
            int second = result.top();
            result.pop();

            if(token == "+")
            {
                result.push(second + first);
            }
            else if(token == "-")
            {
                result.push(second - first);
            }
            else if(token == "/")
            {
                result.push(second/first);
            }
            else if(token == "*")
            {
                result.push(first*second);
            }
            else
            {
                result.push(std::stoi(token));
            }
        }

        return result.top();
    }

private:
    std::stack<int> result;
};


namespace test
{
    void evaluateReversePolishNotationTests()
    {
        EvaluateReversePolishNotation reverse_polish;
        qWarning() << reverse_polish.evalRPN({"2","1","+","3","*"}); //expected 9
        qWarning() << reverse_polish.evalRPN({"4","13","5","/","+"}); //expected 6
        qWarning() << reverse_polish.evalRPN({"10","6","9","3","+","-11","*","/","*","17","+","5","+"}); //expected 22

    }
}
