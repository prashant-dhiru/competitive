#include <vector>

using namespace std;

class Solution {
    int hammingWeight(uint32_t x) {
        x = x - ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = x + (x >> 4);
        x &= 0xF0F0F0F;
        return (x * 0x01010101) >> 24;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> myMap (33);
        vector<int> sol;
        for (const int val: arr)
        {
            myMap[hammingWeight(val)].push_back(val);
        }
        for (auto& arr: myMap)
        {
            if (arr.size() > 0)
            {
                sol.insert(sol.end(), arr.begin(), arr.end());
            }
        }
        return sol;
    }
};