class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[a] = b;
    }

    vector<bool> distanceLimitedPathsExist(
        int n,
        vector<vector<int>>& edgeList,
        vector<vector<int>>& queries) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({
                queries[i][2],
                queries[i][0],
                queries[i][1],
                i
            });
        }
        sort(edgeList.begin(), edgeList.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });
        sort(q.begin(), q.end());
        vector<bool> ans(queries.size());
        int j = 0;
        for (auto &query : q) {
            int limit = query[0];
            int u = query[1];
            int v = query[2];
            int index = query[3];
            while (j < edgeList.size() && edgeList[j][2] < limit) {
                unite(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            ans[index] = (find(u) == find(v));
        }
        return ans;
    }
};