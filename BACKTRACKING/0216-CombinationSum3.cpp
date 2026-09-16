class Solution {
public:
    void solve(int num, int k, int target, vector<int>& temp, vector<vector<int>>& ans) {
        if (k == 0 && target == 0) {
            ans.push_back(temp);
            return;
        }
        if (k == 0 || target < 0 || num > 9) return;

        temp.push_back(num);
        solve(num + 1, k - 1, target - num, temp, ans);
        temp.pop_back();

        solve(num + 1, k, target, temp, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, n, temp, ans);
        return ans;
    }
};