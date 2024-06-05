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
    int findDepth(TreeNode* node){
        if(!node)return 0;
        
        int l=findDepth(node->left);
        int r=findDepth(node->right);
        
        return 1+max(l,r);
    }
    int maxDepth(TreeNode* root) {
        return findDepth(root);
        
    }
};