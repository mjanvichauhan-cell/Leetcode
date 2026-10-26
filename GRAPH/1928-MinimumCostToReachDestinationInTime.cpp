class Solution {
public:
    int minCost(int maxTime,
                vector<vector<int>>& edges,
                vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vector<vector<int>> dist( n, vector<int>(maxTime + 1, INT_MAX));
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>> > pq;
        dist[0][0] = passingFees[0];
        pq.push({passingFees[0], 0, 0});
        while (!pq.empty()) {
            auto [cost, u, time] = pq.top();
            pq.pop();
            if (cost != dist[u][time])
                continue;
            if (u == n - 1)
                return cost;
            for (auto [v, t] : graph[u]) {
                int newTime = time + t;
                if (newTime > maxTime)
                    continue;
                int newCost = cost + passingFees[v];
                if (newCost < dist[v][newTime]) {
                    dist[v][newTime] = newCost;
                    pq.push({ newCost, v, newTime});
                }
            }
        }
        return -1;
    }
};