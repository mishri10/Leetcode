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
    TreeNode* findLCA(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node)return NULL;
        
        if(node==p or node==q)return node;
        
        TreeNode* l=findLCA(node->left,p,q);
        TreeNode* r=findLCA(node->right,p,q);
        
        if(!l)return r;
        if(!r)return l;
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root,p,q);
    }
};