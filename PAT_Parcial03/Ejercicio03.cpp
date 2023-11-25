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
	int timeprev = 0;
	
	std::string temp = value;
	newSet->key = key;
	if (value.length() > 100)
	{
		temp = value.substr(0, 100);
	}
	newSet->key = key;
	newSet->value = temp;
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
			if (regis[i]->key == key)
			{
				timep.push_back(regis[i]);
			}
			i++;
		}
		int j = 0;
		i = 0;
		while (j < timep.size())
		{
			if (timep[j]->time == timestamp)
			{
				resul = timep[j]->value;
				break;
			}
			if (timep[j]->time <= timestamp)
				if (timep[j]->time > i)
				{
					resul = timep[j]->value;
					i = timep[j]->time;
				}
			j++;
		}
	
	return resul;
}
