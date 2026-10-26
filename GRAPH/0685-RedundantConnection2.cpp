class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        parent[a] = b;
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n + 1, 0);
        int first = -1;
        int second = -1;
        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (par[v] == 0) {
                par[v] = u;
            }
            else {
                first = par[v];
                second = i;
                break;
            }
        }
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++) {
            if (i == second)
                continue;
            if (!unite(edges[i][0], edges[i][1])) {
                if (first == -1)
                    return edges[i];
                return {
                    first,
                    edges[second][1]
                };
            }
        }
        return edges[second];
    }
};