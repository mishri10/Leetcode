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
    void traversal(TreeNode* root,string& ans,string& temp){
        if(!root)return;
        if(root->left==NULL and root->right==NULL){
            temp.push_back(root->val+'a');
            string a=temp;
            reverse(a.begin(),a.end());
            if(ans>a)ans=a;
            temp.pop_back();
            return;
        }
        
        temp.push_back(root->val+'a');
        traversal(root->left,ans,temp);
        traversal(root->right,ans,temp);
        temp.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans(25,'z');
        string temp="";
        traversal(root,ans,temp);
        return ans;
    }
};