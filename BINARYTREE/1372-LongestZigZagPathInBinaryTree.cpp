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
    int answer = 0;
    void dfs(TreeNode* root, int leftLen, int rightLen) {
        if (root == nullptr)
            return;
        answer = max(answer, max(leftLen, rightLen));
        if (root->left) {
            dfs(root->left, rightLen + 1, 0);
        }
        if (root->right) {
            dfs(root->right, 0, leftLen + 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        if (root == nullptr)
            return 0;
        dfs(root, 0, 0);
        return answer;
    }
};