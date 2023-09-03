#pragma once

#include <QDebug>

class MergeIntervals
{
public:
    //Time complexity : O(n log n) + O(n)
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end()); //O(n log n)

        std::vector<std::vector<int>> result;
        for(auto current_interval : intervals) //O(n)
        {
            if(result.empty())
            {
                result.push_back(current_interval); //O(1)
                continue;
            }

            auto& last_interval = result.back();
            if(last_interval[1] >= current_interval[0])
            {
                last_interval = {last_interval[0], std::max(current_interval[1], last_interval[1])};
            }
            else
            {
                result.push_back(current_interval);
            }
        }

        return result;
    }
};


namespace test
{
    void MergeIntervalsTests()
    {
        MergeIntervals merge;
        std::vector<std::vector<int>> to_merge{{1,3},{2,6},{8,10},{15,18}};
        qWarning() << merge.merge(to_merge); // 1-4 8-10 15-18

        std::vector<std::vector<int>> to_merge_2{{1,4},{4,5}};
        qWarning() << merge.merge(to_merge_2); // 1-5

        std::vector<std::vector<int>> to_merge_3{{1,4},{2,3}};
        qWarning() << merge.merge(to_merge_3); // 1-4
    }
}
