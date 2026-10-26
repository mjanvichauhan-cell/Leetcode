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
    int kruskal(int n, vector<vector<int>>& edges, int skip, int force) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        int cost = 0;
        int count = 0;
        if (force != -1) {
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];
            if (unite(u, v)) {
                cost += w;
                count++;
            }
        }
        for (int i = 0; i < edges.size(); i++) {
            if (i == skip || i == force)
                continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (unite(u, v)) {
                cost += w;
                count++;
            }
        }
        if (count != n - 1)
            return INT_MAX;
        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });
        int mstCost = kruskal(n, edges, -1, -1);
        vector<int> critical;
        vector<int> pseudo;
        for (int i = 0; i < edges.size(); i++) {
            int withoutEdge = kruskal(n, edges, i, -1);
            if (withoutEdge > mstCost) {
                critical.push_back(edges[i][3]);
                continue;
            }
            int withEdge = kruskal(n, edges, -1, i);
            if (withEdge == mstCost) {
                pseudo.push_back(edges[i][3]);
            }
        }
        return {critical, pseudo};
    }
};