class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        for (auto &it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] == INF || dist[via][j] == INF)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        int city = -1;
        int minCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            if (cnt <= minCount) {
                minCount = cnt;
                city = i;
            }
        }
        return city;
    }
};