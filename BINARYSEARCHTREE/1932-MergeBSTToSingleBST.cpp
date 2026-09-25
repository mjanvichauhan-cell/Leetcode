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
    unordered_map<int, TreeNode*> mp;
    unordered_set<int> childRoots;
    bool dfs(TreeNode* node, long long low, long long high) {
        if (node == nullptr)
            return true;
        if (node->val <= low || node->val >= high)
            return false;
        if (node->left == nullptr && node->right == nullptr &&
            mp.count(node->val)) {
            TreeNode* other = mp[node->val];
            node->left = other->left;
            node->right = other->right;
            mp.erase(node->val);
        }
        return dfs(node->left, low, node->val) &&
               dfs(node->right, node->val, high);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for (TreeNode* root : trees) {
            mp[root->val] = root;
        }
        for (TreeNode* root : trees) {
            if (root->left)
                childRoots.insert(root->left->val);
            if (root->right)
                childRoots.insert(root->right->val);
        }
        TreeNode* root = nullptr;
        for (TreeNode* tree : trees) {
            if (!childRoots.count(tree->val)) {
                if (root != nullptr)
                    return nullptr; 

                root = tree;
            }
        }
        if (root == nullptr)
            return nullptr;
        mp.erase(root->val);
        if (!dfs(root, LLONG_MIN, LLONG_MAX))
            return nullptr;
        if (!mp.empty())
            return nullptr;
        return root;
    }
};