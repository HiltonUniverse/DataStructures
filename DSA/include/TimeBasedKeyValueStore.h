#pragma once

#include <QDebug>
#include <unordered_map>

class TimeMap
{
public:
    TimeMap()
    {
    }

    //-----------------------------------
    void set(const QString& key, const QString& value, int timestamp)
    {
        m_time_map[key].push_back({value, timestamp}); //O(1)
    }

    //-----------------------------------
    //O(log n)
    QString get(const QString& key, int timestamp)
    {
        if(!m_time_map.count(key))
        {
            return "";
        }

        //If we don't get this by reference
        //we will reach Time limit exceedeed as expected!
        auto& value_time_list = m_time_map[key];

        int left = 0;
        int right = value_time_list.size() - 1;
        QString result = "";
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            //if found exact time return instantly
            if(value_time_list[mid].second == timestamp)
            {
                return value_time_list[mid].first;
            }

            if(timestamp > value_time_list[mid].second)
            {
                //this is the closest value and we update this each time target > current time stamp
                //each time we are getting closer and closer to the target so it makes sense to do this in case we don't have
                //our exact target value here.
                result = value_time_list[mid].first;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }

private:
    std::unordered_map<QString, std::vector<std::pair<QString, int>>> m_time_map;
};


namespace test
{
    void timeBasedKeyValueStoreTests()
    {
        TimeMap* time_map = new TimeMap();
        time_map->set("foo", "bar", 1);
        qWarning() << time_map->get("foo", 1);         // return "bar"
        qWarning() << time_map->get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
        time_map->set("foo", "bar2", 4);               // store the key "foo" and value "bar2" along with timestamp = 4.
        qWarning() << time_map->get("foo", 4);         // return "bar2"
        qWarning() << time_map->get("foo", 5);         // return "bar2"
    }
}
