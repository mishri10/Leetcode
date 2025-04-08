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
    TreeNode* deletee(TreeNode* node){
        if(node->left==NULL and node->right==NULL)
            return NULL;

        else if(node->left==NULL)
            return node->right;

        else if(node->right==NULL)
            return node->left;

        else{
            TreeNode* leftChild= node->left;
            TreeNode* rightChild= node->right;

            while(leftChild->right)
                leftChild= leftChild->right;

            leftChild->right=rightChild;

        }
        return node->left;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        

        TreeNode* node=root;

        if(root==NULL)
            return NULL;
            
        if(root->val==key)
            return deletee(root);

        while(node){
            if(node->val>key){
                if(node->left!=NULL and node->left->val==key){
                    node->left=deletee(node->left);
                    return root;
                }
                else
                    node=node->left;
            }

            else{
                if(node->right!=NULL and node->right->val==key){
                    node->right=deletee(node->right);
                    return root;
                }

                else 
                    node=node->right;
            }
        }
        return root;
    }
};