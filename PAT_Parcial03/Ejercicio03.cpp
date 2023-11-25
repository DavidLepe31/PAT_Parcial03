#include "Ejercicio03.h"

TimeMap::TimeMap()
{
	key = "";
	value = "";
	time = 0;
}

void TimeMap::set(string key, string value, int timestamp)
{
	TimeMap* newSet = new TimeMap();
	newSet->key = key;
	newSet->value = value;
	newSet->time = timestamp;
	regis.push_back(newSet);
}

string TimeMap::get(string key, int timestamp)
{
	std::vector<TimeMap*>timep;
	int i = 0;
	while (i < regis.size())
	{
		if (key == regis[i]->key)
		{
			timep.push_back(regis[i]);
		}
		i++;
	}
	i = timestamp;
	while(i>=0)
	{
		int j = 0;
		while (j < timep.size())
		{
			if (timep[j]->time==i)
			{
				return timep[j]->value;
			}
			j++;
		}
		i--;
	}
	return "";
}
