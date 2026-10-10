class Solution {
public:
    struct Node {
        Node* child[26] = {};
        string word = "";
    };
    Node* root = new Node();
    vector<string> ans;
    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->child[i])
                cur->child[i] = new Node();
            cur = cur->child[i];
        }
        cur->word = word;
    }
    void dfs(vector<vector<char>>& board, int r, int c, Node* node) {
        char ch = board[r][c];
        if (ch == '#')
            return;
        Node* next = node->child[ch - 'a'];
        if (!next)
            return;
        if (!next->word.empty()) {
            ans.push_back(next->word);
            next->word = "";
        }
        board[r][c] = '#';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < board.size() &&
                nc >= 0 && nc < board[0].size()) {
                dfs(board, nr, nc, next);
            }
        }
        board[r][c] = ch;
    }
    vector<string> findWords(
        vector<vector<char>>& board,
        vector<string>& words) {
        for (string word : words)
            insert(word);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }
        return ans;
    }
};