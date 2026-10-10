class TrieNode {
public:
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->child[bit] == NULL)
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int getMaxXor(int num) {
        TrieNode* node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->child[1 - bit]) {
                ans |= (1 << i);
                node = node->child[1 - bit];
            } else {
                node = node->child[bit];
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++)
            q.push_back({queries[i][1], queries[i][0], i});
        sort(q.begin(), q.end());
        Trie trie;
        vector<int> ans(queries.size());
        int i = 0;
        for (auto &it : q) {
            int m = it[0];
            int x = it[1];
            int idx = it[2];
            while (i < nums.size() && nums[i] <= m) {
                trie.insert(nums[i]);
                i++;
            }
            if (i == 0)
                ans[idx] = -1;
            else
                ans[idx] = trie.getMaxXor(x);
        }
        return ans;
    }
};