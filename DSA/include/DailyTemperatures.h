#pragma once

#include <QDebug>
#include <stack>

class DailyTemperatures
{
public:
    //Time complexity: O(n)
    //Why is the time complexity O(n)? even with a while loop inside a for loop?
    //- The while loop executes when the current temperature is greater than the temperature at the top of the stack.
    //However, the KEY INSIGHT here is that each element in the temperatures vector is pushed onto the stack and
    //popped from the stack AT MOST ONCE. This is because elements are only pushed when they are greater than the
    //top of the stack, and they are popped when a larger temperature is encountered.
    //In other words, each element is pushed and popped from the stack only once throughout the entire execution of the function.
    //Therefore, the total number of stack operations (pushes and pops) across all iterations of the while loop is proportional.

    //Space complexity: O(n)
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        std::vector<int> result(temperatures.size(), 0);

        using temp_to_index = std::pair<int,int>;
        std::stack<temp_to_index> stack;

        for(int i = 0; i < temperatures.size(); ++i)
        {
            while(!stack.empty() && temperatures[i] > stack.top().first)
            {
                int current_temp_index = i;
                int previous_day_temp_indes = stack.top().second;
                result[previous_day_temp_indes] = current_temp_index - previous_day_temp_indes;
                stack.pop();
            }

            stack.push({temperatures[i], i});
        }

        return result;
    }
};


namespace test
{
    void dailyTemperatureTests()
    {
        DailyTemperatures daily_temperatures;
        std::vector<int> val{73,74,75,71,69,72,76,73};
        qWarning() << daily_temperatures.dailyTemperatures(val);

        std::vector<int> val_2{30,40,50,60};
        qWarning() << daily_temperatures.dailyTemperatures(val_2);

        std::vector<int> val_3{30,60,90};
        qWarning() << daily_temperatures.dailyTemperatures(val_3);
    }
}
