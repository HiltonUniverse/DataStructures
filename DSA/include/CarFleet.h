#pragma once

#include <QDebug>
#include <stack>
#include <map>

class CarFleet
{
public:
    //Time complexity = O(n * log(n))
    //Space complexity = O(n)
    int carFleet(int target, const std::vector<int>& position, const std::vector<int>& speed)
    {
        std::map<int, float> pos_speed;
        //O(n*log(n))
        for(int i = 0; i < position.size(); ++i) //O(n)
        {
            //we want to first look at the car that is at the most front.
            //To make this happen, we can either, sort the position vector and iterate from back to front.
            //Or we can just a map and add negative sign to the position and use the benefit of sorting provided by the map.
            //The time complexity for both are the same.
            //And later when we calculate the time, we have to do: target + pos, instead of target - pos. as pos is already negative.
            pos_speed[-position[i]] = speed[i]; //log(n)
        }

        std::stack<int> stack;
        float slowest_time = -1;
        for(auto [pos,speed] : pos_speed)
        {
            float time = (target  + pos) / speed;
            if(time > slowest_time)
            {
                stack.push(pos);
                slowest_time = time;
            }
        }

        return stack.size();
    }
};


namespace test
{
    void carFleetTests()
    {
        CarFleet car_fleet;
        qWarning() << car_fleet.carFleet(12, {0,8,0,5,3}, {2,4,1,1,3});
        qWarning() << car_fleet.carFleet(10, {3}, {3});
        qWarning() << car_fleet.carFleet(100, {0,2,4}, {4,2,1});
        qWarning() << car_fleet.carFleet(10, {6,8}, {3,2});
    }
}
