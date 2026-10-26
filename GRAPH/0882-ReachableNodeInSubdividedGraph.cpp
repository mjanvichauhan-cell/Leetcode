class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges,int maxMoves, int n) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cnt = e[2];
            graph[u].push_back({v, cnt});
            graph[v].push_back({u, cnt});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u])
                continue;
            for (auto [v, cnt] : graph[u]) {
                int newDist = d + cnt + 1;
                if (newDist < dist[v] &&
                    newDist <= maxMoves) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves)
                ans++;
        }
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cnt = e[2];
            int fromU = maxMoves - dist[u];
            int fromV = maxMoves - dist[v];
            if (fromU < 0) fromU = 0;
            if (fromV < 0) fromV = 0;
            ans += min(cnt, fromU + fromV);
        }
        return ans;
    }
};