/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node)return NULL;
        
        if(node==p or node==q)return node;
        
        TreeNode* l= helper(node->left,p,q);
        TreeNode* r= helper(node->right,p,q);
        
        if(l and r)return node;
        if(!l)return r;
        return l;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};