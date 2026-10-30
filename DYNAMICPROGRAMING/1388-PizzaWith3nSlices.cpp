class Solution {
public:
    int solve(vector<int>& slices, int start, int end) {
        int m = end - start + 1;
        int k = (slices.size()) / 3;
        vector<int> prev2(k + 1, 0), prev1(k + 1, 0), curr(k + 1, 0);
        for (int index = end; index >= start; index--) {
            for (int cnt = 1; cnt <= k; cnt++) {
                int take = slices[index] + prev2[cnt - 1];
                int notTake = prev1[cnt];
                curr[cnt] = max(take, notTake);
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[k];
    }

    int maxSizeSlices(vector<int>& slices) {
        return max(solve(slices, 0, slices.size() - 2), solve(slices, 1, slices.size() - 1));
    }
};