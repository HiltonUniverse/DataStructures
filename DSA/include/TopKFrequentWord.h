#pragma once

#include <QDebug>
#include <vector>
#include <iostream>

#include <unordered_map>
#include <queue>

class TopKFrequentWords
{
public:
    /*Clarification:
    Here K defines the number of most frequent elements.
    if k = 2, then it means to return 2 most frequently repeated elements.
    if k = 4, then return 4 most frequently repeated elements and so on....

    Time Complexity: O(n) + O(n) + O(n) + O(n) * O(n log(k)) = O(4n) + n^2 log(k)
                                                                 = O(n^2 log(k))
    Space complexity = O(n)
    */

    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k)
    {
        std::unordered_map<std::string, int> comp;
        for(const std::string& word : words) //O(n)
        {
            comp[word]++;
        }

        std::vector<std::vector<std::string>> bucket(words.size() + 1);
        for(const auto& [key, value] : comp) //O(n)
        {
            bucket[value].push_back(key);
        }

        std::vector<std::string> result;
        for(size_t i = words.size(); i >= 0; --i) //O(n)
        {
            if(result.size() >= k)
            {
                break;
            }

            if(!bucket[i].empty())
            {
                auto buck = bucket[i];
                if(bucket.size() > 1) //if there is only 1 element, no point in sorting!
                {
                    std::sort(buck.begin(), buck.end()); //O(n log(k)) = n is the size of the bucket vector and k is the maximum number of elements in a bucket.
                }

                int elementsToInsert = std::min(k - static_cast<int>(result.size()), static_cast<int>(buck.size()));
                result.insert(result.end(), buck.begin(), buck.begin() + elementsToInsert);
            }
        }

        return result;
    }

    //-----------------------------------
    /*
        Overall Time Complexity: O(n log(n))
        Overall Space complexity: O(n)
    */
    struct Comparator
    {
        bool operator()(std::pair<int, std::string>& a, std::pair<int, std::string>& b) //O(1)
        {
            if(a.first == b.first) //O(1)
            {
                return a.second > b.second; //lexicographical ordering O(1)
            }

            return a.first < b.first; //max heap comparision O(1)
        }
    };

    //Calculating Time complexity
    //O(n) * O(1) + O(n) * ( O(log(n)) + O(1) ) + O(n) *( O(1) + O(log(n)) )
    //O(n) + O(n log(n)) + O(n) + O(n) + O(n log(n))
    //most dominant terms: O(n log(n)) + O(n log(n)) = 2 * O(n log(n))
    //removing constants: O(n log(n))
    std::vector<QString> topKFrequentBetter(std::vector<std::string>& words, int k)
    {
        std::unordered_map<std::string, int> comp; //Space O(n)
        for(const std::string& word : words) //O(n)
        {
            comp[word]++; //O(1)
        }

        std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, Comparator> pq; //Space O(n)
        for(const auto& [key, value] : comp) //O(n)
        {
            pq.push({value, key});// log(n) + O(1) = log(n) because push triggeres binary heap comparision which is Logarithmic
                                  // and the O(1) = Amortized constant, is from the push_back done by priority_queue in the vector it uses internally.
        }

        std::vector<QString> result; //Space O(n)
        while(k--) //O(n)
        {
            result.push_back(QString::fromStdString(pq.top().second)); // O(1) = Amortized constant.
            pq.pop(); //log(n), just like push, pop also takes a log(n) as it again triggeres binary heap comparision
        }

        return result;
    }
};

//I KNOW NOT THE BEST WAY OF TESTING BUT CAN'T AFFORD TO SPEND TIME ON WRITING UNIT TEST ATM.
namespace test
{
    //-----------------------------------
    void testTopKFrequentWords()
    {
        //input data
        std::vector<std::string> val{"i","love","leetcode","i","love","coding"};
        TopKFrequentWords solution;

        int k = 2; //how many frequenty element to get back from the desired function?
        auto result = solution.topKFrequent(val, k);
        std::vector<std::string> expected_output{"i","love"};

        qWarning() << (expected_output == result);

        //next input data
        k = 4;
        std::vector<std::string> next_val{"the","day","is","sunny","the","the","the","sunny","is","is"};
        result = solution.topKFrequent(next_val, k);
        std::vector<std::string> expected_output_2{"the","is","sunny","day"};

        qWarning() << (expected_output_2 == result);

        k = 1;
        std::vector<std::string> next_val_2{"i","love","leetcode","i","love","coding"};
        result = solution.topKFrequent(next_val_2, k);
        std::vector<std::string> expected_output_3{"i"};
        qWarning() << (expected_output_3 == result);
    }

    //-----------------------------------
    void testTopKFrequentyWordsBetter()
    {
        std::vector<std::string> next_val{"the","day","is","sunny","the","the","the","sunny","is","is"};
        TopKFrequentWords solution;

        qWarning() << solution.topKFrequentBetter(next_val, 4);

        std::vector<std::string> next_val_2{"i","love","leetcode","i","love","coding"};
        auto result = solution.topKFrequentBetter(next_val_2, 3);
        std::vector<std::string> expected_output_3{"i"};
        qWarning() << result;
    }
}
