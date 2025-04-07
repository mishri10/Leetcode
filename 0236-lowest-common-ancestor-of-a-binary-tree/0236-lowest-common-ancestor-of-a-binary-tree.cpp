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
        if(node==NULL)
            return NULL;

        if(node==p or node==q)
            return node;

        TreeNode* lh= findLCA(node->left,p,q);
        TreeNode* rh= findLCA(node->right,p,q);

        if(lh==NULL)
            return rh;
        if(rh==NULL)
            return lh;
        else 
            return node;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root,p,q);
    }
};