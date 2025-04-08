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
    TreeNode* helper(int preStart, int preEnd, int inStart, int inEnd, 
            vector<int>& preorder, vector<int>& inorder, 
            unordered_map<int,int>& mp){

                if(preStart>preEnd)
                    return NULL;

                
                int l= mp[preorder[preStart]]-inStart;
                TreeNode* node= new TreeNode(preorder[preStart]);

                node->left= helper(preStart+1,preStart+l,inStart,
                            mp[preorder[preStart]]-1, preorder, inorder, mp);

                node->right= helper(preStart+l+1,preEnd, 
                            mp[preorder[preStart]]+1, inEnd, preorder, 
                            inorder,mp);
                return node;
            }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int>mp;

        for(int i=0; i<n; i++){
            mp[inorder[i]]=i;
        }

        return helper(0,n-1,0,n-1,preorder,inorder,mp);
    }
};