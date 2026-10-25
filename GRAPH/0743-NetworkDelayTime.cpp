class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n + 1];
        for (auto &it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int node = it.second;
            if (d > dist[node])
                continue;
            for (auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int wt = nbr.second;
                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};