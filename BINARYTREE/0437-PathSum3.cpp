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
    void solve(TreeNode* root, long long k, int &count,
               vector<int>& path)
    {
        if(root == NULL)
            return;
        path.push_back(root->val);
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);
        long long sum = 0;
        for(int i = (int)path.size() - 1; i >= 0; i--)
        {
            sum += path[i];
            if(sum == k)
                count++;
        }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum)
    {
        vector<int> path;
        int count = 0;
        solve(root, targetSum, count, path);
        return count;
    }
};