//Method 1 O(n)
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
    void inorder(TreeNode* root, vector<TreeNode*>& v) {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i]->val > v[i + 1]->val) {
                if (first == NULL)
                    first = v[i];
                second = v[i + 1];
            }
        }
        swap(first->val, second->val);
    }
};

//Method2 O(1)
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
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void calcpointers(TreeNode* root,TreeNode** first,TreeNode** mid,TreeNode** last,TreeNode** prev){
    if(root==NULL) return ;
    calcpointers(root->left,first,mid,last,prev);
    if(*prev && root->val<(*prev)->val){
        if(!*first) {
            *first=*prev;
            *mid=root;
        }
        else{
            *last=root;
        }
    }
    *prev=root;
    calcpointers(root->right,first,mid,last,prev);
}
    void recoverTree(TreeNode* root) {
    TreeNode* first,*mid,*last,*prev;
    first=NULL,mid=NULL,last=NULL,prev=NULL;
    calcpointers(root,&first,&mid,&last,&prev);
    if(first && last){
        swap(&(first->val),&(last->val));
    }
    else if(first && mid){
        swap(&(first->val),&(mid->val));
    }
    }
};