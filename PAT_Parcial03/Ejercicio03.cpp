#include "Ejercicio03.h"
#include <unordered_map>
#include <vector>


std::unordered_map<string, std::vector<std::pair<int, string>>>vreg;

    TimeMap::TimeMap() 
    {

    }

    void TimeMap:: set(string key, string value, int timestamp) 
    {
        vreg[key].push_back({ timestamp,value });
    }

    string TimeMap::get(string key, int timestamp) 
    {
        if (vreg.find(key) == vreg.end()) {
            return "";
        }
        int imin = 0;
        int imax = vreg[key].size() - 1;
        while (imin <= imax) {
            int imid = imin + (imax - imin) / 2;
            if (vreg[key][imid].first < timestamp) {
                imin = imid + 1;
            }
            else if (vreg[key][imid].first > timestamp) {
                imax = imid - 1;
            }
            else
                return vreg[key][imid].second;
        }

        if (imax >= 0)
        {
            return vreg[key][imax].second;
        }

        return "";
    }

