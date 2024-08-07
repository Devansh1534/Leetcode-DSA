#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> memo(n, -1);
        return decode(s, 0, memo);
    }
private:
    int decode(const string &s, int index, vector<int> &memo) {
        int n = s.size();
        if (index == n) return 1;  
        if (s[index] == '0') return 0; 
        if (memo[index] != -1) return memo[index];  
        int ways = decode(s, index + 1, memo);
        if (index < n - 1 && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))) {
            ways += decode(s, index + 2, memo);
        }
        memo[index] = ways;
        return ways;
    }
};