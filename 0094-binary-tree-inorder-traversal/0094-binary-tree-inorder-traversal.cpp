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
        //left,node,right
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*>st;
        
        st.push(root);
        TreeNode* node=root->left;
        
        while(!st.empty() or node!=NULL){
            
            while(node){
                st.push(node);
                node=node->left;
            }
            
            if(st.empty())break;
            ans.push_back(st.top()->val);
            node=st.top()->right;
            st.pop();
        }
        return ans;
    }
};