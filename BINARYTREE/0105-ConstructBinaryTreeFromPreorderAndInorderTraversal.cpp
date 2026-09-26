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
int search(vector<int>&inorder,int start,int end ,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
TreeNode* helper(vector<int> &preorder,vector<int> &inorder,int start,int end,int &idx){
    if(start>end) return NULL;
    int curr=preorder[idx++];
    TreeNode* Node=new TreeNode(curr);
    if(start==end) return Node;
    int pos=search(inorder,start,end,curr);
    Node->left=helper(preorder,inorder,start,pos-1,idx);
    Node->right=helper(preorder,inorder,pos+1,end,idx);
    return Node;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
       return helper(preorder,inorder,0,inorder.size()-1,idx);
    }
};