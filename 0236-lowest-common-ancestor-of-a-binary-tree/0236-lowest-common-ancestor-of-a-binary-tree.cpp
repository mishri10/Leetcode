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
    bool findPath(TreeNode* node, TreeNode* target, vector<TreeNode*>& path){
        if(node==NULL)
            return 0;

        if(node==target){
            path.push_back(node);
            return 1;
        }

        path.push_back(node);
        bool l= findPath(node->left,target,path);
        bool r= findPath(node->right,target,path);

        if(l or r)
            return 1;
        
        path.pop_back();
        return 0;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1,path2;

        findPath(root,p,path1);
        findPath(root,q,path2);

        TreeNode* ans;
        int n= min(path1.size(),path2.size());

        for(int i=0; i<n; i++){
            if(path1[i]==path2[i])
                ans=path1[i];
        }

        return ans;

    }
};