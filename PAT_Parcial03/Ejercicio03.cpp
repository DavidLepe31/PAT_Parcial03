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
	std::string resul="";
	while (i < regis.size())
	{
		if (key == regis[i]->key)
		{
			timep.push_back(regis[i]);
		}
		i++;
	}
	int j = 0;
	while (j < timep.size() && timep[j]->time<=timestamp)
	{
		j++;
	}
	if (j > 0)
	{
		if (j = timep.size())
		{
			j = j - 1;
		}
		if (timep[j]->time > timestamp)
		{
			j = j - 1;
		}
		if (timep[j]->time <= timestamp)
		{
			resul = timep[j]->value;
		}
		
	}
	return resul;
}
