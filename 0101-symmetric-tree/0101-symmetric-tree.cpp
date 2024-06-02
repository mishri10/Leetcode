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
    bool check(TreeNode* l, TreeNode* r){
        if(l==NULL or r==NULL)return l==r;
        
        if(l->val!=r->val)return 0;
        
        return check(l->right,r->left) and check(l->left,r->right);
    }
    bool isSymmetric(TreeNode* root) {
        
              
        return check(root->left,root->right);
    }
};