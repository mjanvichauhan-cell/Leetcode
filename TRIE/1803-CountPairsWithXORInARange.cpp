class Solution {
public:
    struct Node {
        Node* child[2] = {nullptr, nullptr};
        int cnt = 0;
    };
    Node* root;

    void insert(int x) {
        Node* cur = root;
        for (int i = 14; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (!cur->child[b])
                cur->child[b] = new Node();
            cur = cur->child[b];
            cur->cnt++;
        }
    }

    int countLessEqual(int x, int limit) {
        if (limit < 0) return 0;
        Node* cur = root;
        int ans = 0;
        for (int i = 14; i >= 0; i--) {
            if (!cur) break;
            int xb = (x >> i) & 1;
            int lb = (limit >> i) & 1;
            if (lb == 1) {
                if (cur->child[xb])
                    ans += cur->child[xb]->cnt;
                cur = cur->child[1 - xb];
            } else {
                cur = cur->child[xb];
            }
        }
        if (cur)
            ans += cur->cnt;
        return ans;
    }

    int countPairs(vector<int>& nums, int low, int high) {
        root = new Node();
        long long ans = 0;
        for (int x : nums) {
            ans += countLessEqual(x, high);
            ans -= countLessEqual(x, low - 1);
            insert(x);
        }
        return ans;
    }
};