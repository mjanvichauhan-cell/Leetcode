class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tin, low, vis;
    int timer = 0;
    void dfs(int node, int parent, vector<vector<int>> &adj) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for (int next : adj[node]) {
            if (next == parent)
                continue;
            if (!vis[next]) {
                dfs(next, node, adj);
                low[node] = min(low[node], low[next]);
                if (low[next] > tin[node])
                    ans.push_back({node, next});
            }
            else {
                low[node] = min(low[node], tin[next]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        tin.resize(n);
        low.resize(n);
        vis.assign(n, 0);
        dfs(0, -1, adj);
        return ans;
    }
};