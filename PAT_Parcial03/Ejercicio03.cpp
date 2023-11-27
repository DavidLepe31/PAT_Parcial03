#include "Ejercicio03.h"
#include <map>
#include <iterator>

TimeMap::TimeMap()
{
    map = new unordered_map<string, vector<Pair*>>();
}

void TimeMap::set(string key, string value, int timestamp)
{
    (*map)[key].emplace_back(new Pair{ timestamp, value });
}

string TimeMap::get(string key, int timestamp)
{
    if (map->find(key) == map->end())
    {
        return "";
    }
    vector<Pair*> val = (*map)[key];

    unsigned int high = val.size();
    unsigned int low = 0;
    unsigned int middle;

    if (val[low]->timestamp > timestamp)
    {
        return "";
    }
    if (val[high - 1]->timestamp <= timestamp)
        return val[high - 1]->value;

    while (low < high) {
        middle = (high + low) >> 1;

        if (val[middle]->timestamp == timestamp)
            return val[middle]->value;

        if (val[middle]->timestamp < timestamp)
            low = middle + 1;
        else
            high = middle;
    }

    return val[middle]->value;
}

TimeMap::~TimeMap()
{
    for (auto& entry : *map) {
        for (auto& pair : entry.second) {
            delete pair;
        }
    }
    delete map;
}
}

