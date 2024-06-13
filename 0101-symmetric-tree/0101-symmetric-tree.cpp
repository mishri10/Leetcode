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
    bool isSymmetric(TreeNode* root) {
        
        stack<TreeNode*>st1,st2;
        
        st1.push(root->left);
        st2.push(root->right);
        
        while(!st1.empty() and !st2.empty()){
            TreeNode* node1=st1.top();
            st1.pop();
            TreeNode* node2=st2.top();
            st2.pop();
            
            if(node1==NULL and node2==NULL)continue;
            
            if(node1==NULL and node2!=NULL)return 0;
            if(node1!=NULL and node2==NULL)return 0;
            
            if(node1->val != node2->val)return 0;
            
            if(node1){
                st1.push(node1->right);
                st1.push(node1->left);}
            if(node2){
                st2.push(node2->left);
                st2.push(node2->right);}
        }
        
        return 1;
    }
};

// base case
// if(l ==NULL or r==NULL)return l==r
// if(l->val!=r->val)return false;
// recursive function
// (l->right and r->left) and (l->left and r->right)
//T.C: O(N), S.C: O(H)



