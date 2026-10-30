class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int> next(n + 2, 0);
        vector<int> curr(n + 2, 0);
        for (int index = n - 1; index >= 0; index--) {
            for (int time = index + 1; time >= 1; time--) {
                int include = satisfaction[index] * time + next[time + 1];
                int exclude = next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[1];
    }
};