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
    bool findPath(TreeNode* node, TreeNode* target, vector<TreeNode*>&path){
        if(node==NULL)
            return 0;

        path.push_back(node);

        if(node==target)
            return 1;
        //
        bool lh= findPath(node->left,target,path);
        bool rh= findPath(node->right,target,path);

        if(lh or rh)
            return 1;

        path.pop_back();
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>p1,p2;
        findPath(root,p,p1);
        findPath(root,q,p2);
        TreeNode* ans=NULL;

        int m=min(p1.size(),p2.size());

        for(int i=0; i<m; i++){
            if(p1[i]==p2[i])
                ans= p1[i];
        }

        return ans;
    }
};