#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        sort(nums.begin(), nums.end(), [&freqMap](int a, int b) {
            if (freqMap[a] != freqMap[b]) {
                return freqMap[a] < freqMap[b];
            }
            return a > b;
        });
        
        return nums;
    }
};
