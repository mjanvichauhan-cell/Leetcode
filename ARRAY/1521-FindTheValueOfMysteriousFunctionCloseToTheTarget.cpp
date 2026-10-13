class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> prev;
        int ans = INT_MAX;
        for (int x : arr) {
            unordered_set<int> cur;
            cur.insert(x);
            for (int v : prev) {
                cur.insert(v & x);
            }
            for (int v : cur) {
                ans = min(ans, abs(v - target));
            }
            prev = cur;
        }
        return ans;
    }
};