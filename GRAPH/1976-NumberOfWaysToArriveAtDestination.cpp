class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<pair<int,int>> adj[n];
        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long d = it.first;
            int node = it.second;
            if (d > dist[node])
                continue;
            for (auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int wt = nbr.second;
                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if (d + wt == dist[adjNode]) {
                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};