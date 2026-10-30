class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> pre(n, 0);
        for (auto &e : relations)
            pre[e[1] - 1] |= (1 << (e[0] - 1));
        int total = 1 << n;
        vector<int> dist(total, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            int mask = q.front();
            q.pop();
            if (mask == total - 1)
                return dist[mask];
            int available = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0 && (pre[i] & mask) == pre[i])
                    available |= (1 << i);
            }

            if (__builtin_popcount(available) <= k) {
                int nextMask = mask | available;
                if (dist[nextMask] == -1) {
                    dist[nextMask] = dist[mask] + 1;
                    q.push(nextMask);
                }
            } else {
                for (int sub = available; sub; sub = (sub - 1) & available) {
                    if (__builtin_popcount(sub) == k) {
                        int nextMask = mask | sub;
                        if (dist[nextMask] == -1) {
                            dist[nextMask] = dist[mask] + 1;
                            q.push(nextMask);
                        }
                    }
                }
            }
        }
        return -1;
    }
};