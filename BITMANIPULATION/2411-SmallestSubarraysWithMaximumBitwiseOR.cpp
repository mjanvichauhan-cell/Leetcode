class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> last(32, -1);

        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b))
                    last[b] = i;
            }
            int end = i;

            for (int b = 0; b < 32; b++) {
                if (last[b] != -1)
                    end = max(end, last[b]);
            }
            ans[i] = end - i + 1;
        }

        return ans;
    }
};