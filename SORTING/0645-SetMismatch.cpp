class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2);
        for (int x : nums) {
            int idx = abs(x) - 1;
            if (nums[idx] < 0)
                ans[0] = abs(x);
            else
                nums[idx] = -nums[idx];
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};