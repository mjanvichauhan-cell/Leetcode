class MajorityChecker {
    struct Node {
        int val;
        int cnt;
    };

    vector<int> arr;
    vector<Node> tree;
    unordered_map<int, vector<int>> positions;

    Node merge(Node a, Node b) {
        if (a.val == b.val)
            return {a.val, a.cnt + b.cnt};
        if (a.cnt > b.cnt)
            return {a.val, a.cnt - b.cnt};
        return {b.val, b.cnt - a.cnt};
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {arr[l], 1};
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node queryTree(int node, int l, int r,int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        if (qr <= mid)
            return queryTree(node * 2, l, mid, ql, qr);
        if (ql > mid)
            return queryTree(node * 2 + 1,mid + 1, r,ql, qr);
        return merge(queryTree(node * 2, l, mid, ql, qr),  queryTree(node * 2 + 1, mid + 1, r, ql, qr) );
    }

public:

    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        int n = arr.size();
        tree.resize(4 * n);
        for (int i = 0; i < n; i++)
            positions[arr[i]].push_back(i);
        build(1, 0, n - 1);
    }

    int query(int left, int right, int threshold) {
        Node candidate =
            queryTree(1, 0, arr.size() - 1,left, right);

        int x = candidate.val;
        auto &v = positions[x];
        auto it1 = lower_bound(v.begin(), v.end(), left);
        auto it2 = upper_bound(v.begin(), v.end(), right);
        int count = it2 - it1;
        if (count >= threshold)
            return x;
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */