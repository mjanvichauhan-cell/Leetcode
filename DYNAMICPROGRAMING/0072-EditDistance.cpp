class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> next(m + 1, 0), curr(m + 1, 0);
        for (int j = 0; j <= m; j++)
            next[j] = m - j;
        for (int i = n - 1; i >= 0; i--) {
            curr[m] = n - i;
            for (int j = m - 1; j >= 0; j--) {
                if (word1[i] == word2[j])
                    curr[j] = next[j + 1];
                else
                    curr[j] = 1 + min(next[j], min(curr[j + 1], next[j + 1]));
            }
            next = curr;
        }
        return next[0];
    }
};