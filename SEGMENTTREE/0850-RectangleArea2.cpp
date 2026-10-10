class Solution {
public:
    static const int MOD = 1e9 + 7;
    struct Event {
        int x, y1, y2, type;
        bool operator<(const Event& other) const {
            return x < other.x;
        }
    };

    vector<int> ys;
    vector<int> tree, count;

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            count[node] += val;
        } else {
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid + 1, r, ql, qr, val);
        }
        if (count[node] > 0) {
            tree[node] = ys[r + 1] - ys[l];
        } else if (l == r) {
            tree[node] = 0;
        } else {
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<Event> events;
        for (auto& rect : rectangles) {
            int x1 = rect[0];
            int y1 = rect[1];
            int x2 = rect[2];
            int y2 = rect[3];
            ys.push_back(y1);
            ys.push_back(y2);
            events.push_back({x1, y1, y2, 1});
            events.push_back({x2, y1, y2, -1});
        }
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        sort(events.begin(), events.end());
        int n = ys.size() - 1;
        tree.resize(4 * n);
        count.resize(4 * n);
        long long ans = 0;
        long long prevX = events[0].x;
        for (auto& e : events) {
            long long width = e.x - prevX;
            ans = (ans + width * tree[1]) % MOD;
            int y1 = lower_bound(ys.begin(), ys.end(), e.y1) - ys.begin();
            int y2 = lower_bound( ys.begin(), ys.end(), e.y2 ) - ys.begin();
            update(1, 0, n - 1, y1, y2 - 1, e.type);
            prevX = e.x;
        }
        return ans;
    }
};