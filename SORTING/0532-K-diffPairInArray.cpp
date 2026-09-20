class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;
        int ans = 0;
        for (auto &[x, count] : freq) {
            if (k == 0) {
                if (count >= 2)
                    ans++;
            } else {
                if (freq.count(x + k))
                    ans++;
            }
        }
        return ans;
    }
};