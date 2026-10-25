class Solution {
public:
    vector<int> shortestAlternatingPaths(int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : redEdges)
            adj[e[0]].push_back({e[1], 0});
        for (auto &e : blueEdges)
            adj[e[0]].push_back({e[1], 1});
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        visited[0][0] = true;
        visited[0][1] = true;
        vector<int> ans(n, -1);
        ans[0] = 0;
        int distance = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, prevColor] = q.front();
                q.pop();
                for (auto [next, color] : adj[node]) {
                    if (color == prevColor)
                        continue;
                    if (!visited[next][color]) {
                        visited[next][color] = true;
                        if (ans[next] == -1)
                            ans[next] = distance + 1;
                        q.push({next, color});
                    }
                }
            }
            distance++;
        }
        return ans;
    }
};