class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            int mask = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j])
                    mask |= (1 << j);
            }
            if (mask == 0)
                return {i};
            if (!mp.count(mask))
                mp[mask] = i;
        }

        for (auto &[mask1, idx1] : mp) {
            for (auto &[mask2, idx2] : mp) {
                if ((mask1 & mask2) == 0) {
                    if (idx1 < idx2)
                        return {idx1, idx2};
                    else
                        return {idx2, idx1};
                }
            }
        }
        return {};
    }
};