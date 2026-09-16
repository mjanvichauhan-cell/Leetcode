class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& bucket, int index, int target) {
        if (index == nums.size())
            return true;
        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] + nums[index] > target)
                continue;
            if (i > 0 && bucket[i] == bucket[i - 1])
                continue;
            bucket[i] += nums[index];
            if (solve(nums, bucket, index + 1, target))
                return true;
            bucket[i] -= nums[index];
            if (bucket[i] == 0)
                break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int x : nums)
            sum += x;
        if (sum % k != 0)
            return false;
        int target = sum / k;
        for (int x : nums) {
            if (x > target)
                return false;
        }
        sort(nums.rbegin(), nums.rend());
        vector<int> bucket(k, 0);
        return solve(nums, bucket, 0, target);
    }
};