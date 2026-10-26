class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto &e : relations) {
            adj[e[0] - 1].push_back(e[1] - 1);
            indegree[e[1] - 1]++;
        }

        queue<int> q;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = time[i];
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int next : adj[node]) {
                dp[next] = max(dp[next], dp[node] + time[next]);
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};