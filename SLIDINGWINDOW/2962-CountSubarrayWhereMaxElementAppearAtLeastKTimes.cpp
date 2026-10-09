class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int left = 0;
        int count = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == maxi)
                count++;
            while (count >= k) {
                ans += nums.size() - right;
                if (nums[left] == maxi)
                    count--;
                left++;
            }
        }
        return ans;
    }
};