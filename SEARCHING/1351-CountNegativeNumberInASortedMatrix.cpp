class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (auto &row : grid) {
            int low = 0, high = row.size() - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (row[mid] < 0)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            ans += row.size() - low;
        }
        return ans;
    }
};