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
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        else if(root1 ==NULL or root2==NULL){
        return false;
    }
    else{
        bool cond1=root1->val==root2->val;
        bool cond2=isSameTree(root1->left,root2->left);
        bool cond3=isSameTree(root1->right,root2->right);
        if(cond1 && cond2 && cond3) return true;
        return false;
    } 
    }
};