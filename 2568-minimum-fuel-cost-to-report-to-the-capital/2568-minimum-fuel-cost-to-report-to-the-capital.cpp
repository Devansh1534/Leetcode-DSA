#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    long long dfs(int node, int parent, vector<vector<int>>& adj, int seats, long long& fuel) {
        int representatives = 1;
        
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                representatives += dfs(neighbor, node, adj, seats, fuel);
            }
        }

        if (node != 0) {
            fuel += (representatives + seats - 1) / seats;
        }

        return representatives;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        
        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        
        long long fuel = 0;
        dfs(0, -1, adj, seats, fuel);
        return fuel;
    }
};
