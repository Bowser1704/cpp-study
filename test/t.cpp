#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        if (groupSizes.size() == 1) {
            vector<int> res {0};
            result.push_back(res);
            return result;
        }
        map<int, vector<int>> mapresult;
        map<int, int> mapgroup;
        for (int i=0; i<groupSizes.size(); i++) {
            if(!mapgroup[groupSizes[i]]) mapgroup[groupSizes[i]] = groupSizes[i];
            if (mapresult[mapgroup[groupSizes[i]]].size() == groupSizes[i]) {
                mapgroup[groupSizes[i]] += 500;
            }
            mapresult[mapgroup[groupSizes[i]]].push_back(i);
        }
        for (auto i = mapresult.begin(); i != mapresult.end(); ++i) {
            result.push_back(i->second);
        }
        return result;
    }
};