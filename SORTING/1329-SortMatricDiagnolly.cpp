class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        for (int start = 0; start < m; start++) {
            vector<int> v;
            int i = start, j = 0;
            while (i < m && j < n) {
                v.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(v.begin(), v.end());
            i = start, j = 0;
            int k = 0;
            while (i < m && j < n) {
                mat[i][j] = v[k++];
                i++;
                j++;
            }
        }

        for (int start = 1; start < n; start++) {
            vector<int> v;
            int i = 0, j = start;
            while (i < m && j < n) {
                v.push_back(mat[i][j]);
                i++;
                j++;
            }
            sort(v.begin(), v.end());
            i = 0, j = start;
            int k = 0;
            while (i < m && j < n) {
                mat[i][j] = v[k++];
                i++;
                j++;
            }
        }

        return mat;
    }
};