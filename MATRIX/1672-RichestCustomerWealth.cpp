class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int best = 0;
        for (auto &acc : accounts) {
            int sum = 0;
            for (int v : acc) sum += v;
            best = max(best, sum);
        }
        return best; 
    }
};