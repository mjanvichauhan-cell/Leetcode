class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
            tree.resize(4 * n);
            build(nums, 1, 0, n - 1);
        }
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int index, int val) {
        updateTree(1, 0, n - 1, index, val);
    }

    void updateTree(int node, int start, int end,int index, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (index <= mid)
            updateTree(2 * node, start, mid, index, val);
        else
            updateTree(2 * node + 1, mid + 1, end, index, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || end < left)
            return 0;
        if (left <= start && end <= right)
            return tree[node];
        int mid = start + (end - start) / 2;
        return query(2 * node, start, mid, left, right) +
               query(2 * node + 1, mid + 1, end, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */