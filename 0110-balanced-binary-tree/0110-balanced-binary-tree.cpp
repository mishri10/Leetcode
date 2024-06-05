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
    int check(TreeNode* node){
        if(!node)return 0;
        
        int l=check(node->left);
        int r=check(node->right);
        if(l==-1 or r==-1)return -1;
        if(abs(l-r)>1)return -1;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(check(root)==-1)return 0;
        return 1;
    }
};