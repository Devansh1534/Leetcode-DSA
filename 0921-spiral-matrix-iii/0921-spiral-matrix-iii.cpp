#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<int> directions = {0, 1, 0, -1, 0}; 
        int steps = 1; 
        
        result.push_back({rStart, cStart});
        
        while (result.size() < R * C) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < steps; ++j) {
                    rStart += directions[i];
                    cStart += directions[i + 1];
                    if (rStart >= 0 && rStart < R && cStart >= 0 && cStart < C) {
                        result.push_back({rStart, cStart});
                    }
                }
                if (i % 2 == 1) {
                    ++steps;
                }
            }
        }
        
        return result;
    }
};
