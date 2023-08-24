#pragma once

#include <QDebug>

class GeneratePrantheses
{
public:
    //Time complexity is actually complex but generally we can say it's: O(2^n).
    //Because every node can have 2 child node. And the behaviour is exponential.
    //Each level has: 2^0, 2^1, 2^2, 2^3, 2^4, 2^5..etc so 2^n.

    //space complexity is the same, we include the amount of space consumed in the stack: O(2^n)

    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> results;
        startGeneration(n, 0, 0, "", results);
        return results;
    }

private:
    void startGeneration(int n, int open, int close, const std::string& combination, std::vector<std::string>& results)
    {
        if(open == n && close == n)
        {
            results.push_back(combination);
            return;
        }

        if(open < n)
        {
            startGeneration(n, open + 1, close, combination + "(", results);
        }

        if(open > close)
        {
            startGeneration(n, open, close + 1, combination + ")", results);
        }
    }
};

namespace test
{
    void generateParenthesesTest()
    {
        GeneratePrantheses generate;
        generate.generateParenthesis(3); //expected ["((()))","(()())","(())()","()(())","()()()"]
        generate.generateParenthesis(2); //expected ["(())", "()()"]
    }
}
