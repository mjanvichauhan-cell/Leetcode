class Solution {
public:
    struct TrieNode {
        TrieNode* child[2];
        int cnt;
        TrieNode() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(int x) {
        TrieNode* cur = root;
        cur->cnt++;
        for (int bit = 17; bit >= 0; bit--) {
            int b = (x >> bit) & 1;
            if (!cur->child[b])
                cur->child[b] = new TrieNode();
            cur = cur->child[b];
            cur->cnt++;
        }
    }

    void remove(int x) {
        TrieNode* cur = root;
        cur->cnt--;
        for (int bit = 17; bit >= 0; bit--) {
            int b = (x >> bit) & 1;
            cur = cur->child[b];
            cur->cnt--;
        }
    }

    int getMaxXor(int x) {
        TrieNode* cur = root;
        int ans = 0;
        for (int bit = 17; bit >= 0; bit--) {
            int b = (x >> bit) & 1;
            int opposite = 1 - b;
            if (cur->child[opposite] &&
                cur->child[opposite]->cnt > 0) {
                ans |= (1 << bit);
                cur = cur->child[opposite];

            } else {
                cur = cur->child[b];
            }
        }
        return ans;
    }

    vector<vector<int>> tree;
    vector<vector<pair<int, int>>> queries;
    vector<int> answer;

    void dfs(int node) {
        insert(node);
        for (auto& q : queries[node]) {
            int value = q.first;
            int index = q.second;

            answer[index] = getMaxXor(value);
        }
        for (int child : tree[node]) {
            dfs(child);
        }
        remove(node);
    }
    vector<int> maxGeneticDifference(
        vector<int>& parents,
        vector<vector<int>>& queriesInput) {
        int n = parents.size();
        tree.resize(n);
        queries.resize(n);
        answer.resize(queriesInput.size());
        int rootNode = -1;
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) {
                rootNode = i;
            } else {
                tree[parents[i]].push_back(i);
            }
        }
        for (int i = 0; i < queriesInput.size(); i++) {
            int node = queriesInput[i][0];
            int val = queriesInput[i][1];
            queries[node].push_back({val, i});
        }
        dfs(rootNode);
        return answer;
    }
};