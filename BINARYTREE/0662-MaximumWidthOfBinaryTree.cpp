/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    unsigned long long maxwidth = 0; 
    while (!q.empty()) {
        int currlevelsize = q.size();
        unsigned long long stidx = q.front().second;
        unsigned long long endidx = q.back().second; 
        maxwidth = max(maxwidth, endidx - stidx + 1);
        for (int i = 0; i < currlevelsize; i++) {
            auto curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            unsigned long long idx = curr.second - stidx; 
            if (node->left) 
                q.push({node->left, 2 * idx + 1});
            if (node->right) 
                q.push({node->right, 2 * idx + 2});
        }
    }
    return (int)maxwidth;
}
};