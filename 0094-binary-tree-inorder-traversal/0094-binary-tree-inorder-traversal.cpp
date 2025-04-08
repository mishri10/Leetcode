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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;

        TreeNode* node=root;

        while(node){
            if(node->left){
                TreeNode* l= node->left;
                while(l->right!=NULL and l->right!=node){
                    l=l->right;
                }
                
                if(l->right==NULL){
                    l->right=node;
                    node=node->left;
                }

                else{
                    ans.push_back(node->val);
                    l->right=NULL;
                    node=node->right;
                }

            }

            else{
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};