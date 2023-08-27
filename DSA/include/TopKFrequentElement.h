#pragma once

#include <QDebug>
#include <vector>
#include <queue>

#include <unordered_map>

class TopKFrequentElement
{
public:
    /*Clarification:
    Here K defines the number of most frequent elements.
    if k = 2, then it means to return 2 most frequently repeated elements.
    if k = 4, then return 4 most frequently repeated elements and so on....

    Time complexity = O(n) + O(n) + O(k) = O(2n) = O(n);
    Space complexity = O(n) + O(n) + O(k) = O(2n) = O(n);
    */

    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> comp;
        for(const int num : nums)
        {
            comp[num]++;
        }

        std::vector<std::vector<int>> bucket(nums.size() + 1);
        for(const auto& [key, value] : comp)
        {
            bucket[value].push_back(key);
        }

        std::vector<int> result;
        for(size_t i = nums.size(); i >= 0; --i)
        {
            if(result.size() >= k)
            {
                break;
            }

            if(!bucket[i].empty())
            {
                auto bucket_content = bucket[i];
                result.insert(result.end(), bucket_content.begin(), bucket_content.end());
            }
        }

        return result;
    }

    //-----------------------------------
    struct Comparator
    {
        //max queue
        bool operator()(std::pair<int, int>& a, std::pair<int, int>& b) //O(1)
        {
            return a.first < b.first;
        }

        //min queue
        //bool operator()(std::pair<int, int>& a, std::pair<int, int>& b) //O(1)
        //{
            //return a.first > b.first;
        //}
    };

    //Time Complexity: O(n) + O(n log n) + O(k * log n) = O( n log n)
    std::vector<int> topKFrequentQueue(std::vector<int>& nums, int k)
    {
        std::unordered_map<int,int> count;
        for(int num : nums) //O(n)
        {
            count[num]++;
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> queue;
        //std::priority_queue<std::pair<int,int>> queue;
        //O(n) * O(log n) = O(n log n)
        for(auto [key, value] : count) //O(n)
        {
            queue.push({value, key}); //O(log n)
        }

        std::vector<int> result;
        //O(k-1) * O(log n) = O(k * log n)
        for(int i = k - 1; i >= 0; --i) //O(k - 1)
        {
            result.push_back(queue.top().second); //O(1)
            queue.pop();//O(log n)
        }

        return result;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    void testTopKFrequent()
    {
        //input data
        std::vector<int> val{1,1,1,2,2,3};
        TopKFrequentElement solution;

        int k = 2; //how many frequenty element to get back from the desired function?
        auto result = solution.topKFrequent(val, k);
        std::vector<int> expected_output{1,2};

        qWarning() << (expected_output == result);

        //next input data
        //Input: nums = [1], k = 1
        //Output: [1]
        k = 1;
        std::vector<int> next_val{1};
        result = solution.topKFrequent(next_val, k);
        std::vector<int> expected_output_2{1};

        qWarning() << (expected_output_2 == result);

    }
}
