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
	if ((key.length() > 0 && key.length() < 101) && (value.length() > 0 && value.length() < 101) && (timestamp >0 && timestamp <= pow(10, 7)))
	{
		newSet->key = key;
		newSet->value = value;
		newSet->time = timestamp;
		regis.push_back(newSet);
	}
}

string TimeMap::get(string key, int timestamp)
{
	std::vector<TimeMap*>timep;
	int i = 0;
	std::string resul="";
	if ((key.length() > 0 && key.length() < 101) && (timestamp > 0 && timestamp <= pow(10, 7)))
	{
		while (i < regis.size())
		{
			if (regis[i]->key == key)
			{
				timep.push_back(regis[i]);
			}
			i++;
		}
		int j = 0;
			while (j < timep.size() && timep[j]->time <= timestamp)
			{
				j++;
			}
		if (timep.size() > 0)
		{
			if (j >= timep.size())
			{
				j -= 1;
			}
			if (timep[j]->time > timestamp)
			{
				if (j > 0)
				{
					j -= 1;
				}
			}
			if (timep[j]->time <= timestamp)
			{
				resul = timep[j]->value;
			}
		}
	}
	return resul;
}
