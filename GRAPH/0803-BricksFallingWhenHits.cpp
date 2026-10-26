class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int getSize(int x) {
        return sz[find(x)];
    }

    vector<int> hitBricks( vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> g = grid;
        for (auto &h : hits) {
            if (g[h[0]][h[1]] == 1)
                g[h[0]][h[1]] = 0;
        }
        int total = m * n;
        int roof = total;
        parent.resize(total + 1);
        sz.assign(total + 1, 1);
        for (int i = 0; i <= total; i++)
            parent[i] = i;
        auto id = [&](int r, int c) {
            return r * n + c;
        };
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (g[r][c] == 0)
                    continue;
                int cur = id(r, c);
                if (r == 0)
                    unite(cur, roof);
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && g[nr][nc] == 1) {
                        unite(cur, id(nr, nc));
                    }
                }
            }
        }

        vector<int> ans(hits.size());
        for (int i = hits.size() - 1; i >= 0; i--) {
            int r = hits[i][0];
            int c = hits[i][1];
            if (grid[r][c] == 0)
                continue;
            int before = getSize(roof);
            g[r][c] = 1;
            int cur = id(r, c);
            if (r == 0)
                unite(cur, roof);
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && g[nr][nc] == 1) {
                    unite(cur, id(nr, nc));
                }
            }
            int after = getSize(roof);
            ans[i] = max(0, after - before - 1);
        }
        return ans;
    }
};