class Solution {
public:
    int solve(vector<int>& nums, int index, int currentXor) {
        if (index == nums.size())
            return currentXor;
        int take = solve(nums, index + 1, currentXor ^ nums[index]);
        int notTake = solve(nums, index + 1,currentXor);
        return take + notTake;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};
