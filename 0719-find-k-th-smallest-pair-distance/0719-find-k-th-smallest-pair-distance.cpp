class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums.front();

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0, j = 0;

            for (int i = 0; i < nums.size(); i++) {
                while (j < nums.size() && nums[j] - nums[i] <= mid) {
                    j++;
                }
                count += j - i - 1;
            }

            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
