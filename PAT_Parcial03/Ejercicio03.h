#pragma once

#include <string>
#include<vector>

using std::string;

class TimeMap
{
public:
	string value;
	string key;
	int time;
	
	std::vector<TimeMap*>regis;
	TimeMap();

	void set(string key, string value, int timestamp);

	string get(string key, int timestamp);
};

