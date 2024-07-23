#include <unordered_map>

using namespace std;

// Assuming TreeNode is already defined as:
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1;  
        return dfs(root, 0, sum, prefixSumCount);
    }

private:
    int dfs(TreeNode* node, long long currSum, int target, unordered_map<long long, int>& prefixSumCount) {
        if (!node) return 0;

        currSum += node->val;
        int numPathsToCurr = prefixSumCount[currSum - target];

        prefixSumCount[currSum]++;
        
        int result = numPathsToCurr + dfs(node->left, currSum, target, prefixSumCount) + dfs(node->right, currSum, target, prefixSumCount);

        prefixSumCount[currSum]--;

        return result;
    }
};
