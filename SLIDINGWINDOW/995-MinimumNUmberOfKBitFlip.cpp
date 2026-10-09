class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flipped(n, 0);
        int flipCount = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k)
                flipCount ^= flipped[i - k];
            if ((nums[i] ^ flipCount) == 0) {
                if (i + k > n)
                    return -1;
                ans++;
                flipCount ^= 1;
                flipped[i] = 1;
            }
        }
        return ans;
    }
};