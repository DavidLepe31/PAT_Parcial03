#include "Ejercicio03.h"
#include <map>
#include <iterator>

TimeMap::TimeMap()
{
    orden = new unordered_map<string, vector<Pair*>>();
}

void TimeMap::set(string key, string value, int timestamp)
{
    (*orden)[key].emplace_back(new Pair{ timestamp, value });
}

string TimeMap::get(string key, int timestamp)
{
    if (orden->find(key) == orden->end())
        return "";

    vector<Pair*> val = (*orden)[key];

    unsigned int high = val.size();
    unsigned int low = 0;
    unsigned int middle;

    if (val[low]->timestamp > timestamp)
        return "";

    if (val[high - 1]->timestamp <= timestamp)
        return val[high - 1]->value;

    while (low < top) {
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
    for (auto& entry : *orden) {
        for (auto& pair : entry.second) {
            delete pair;
        }
    }
    delete orden;
}
}

