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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q; //node,val
        
        q.push({root,0});
        long long int ans=1;
        int maxi=0,mini=0;
    
        while(!q.empty()){
            int n=q.size();
            maxi=INT_MIN;
            mini=INT_MAX;
            for(int i=0;i<n;i++){
            TreeNode* node=q.front().first;
            long long int val= q.front().second;
            q.pop();
            if(maxi<val)maxi=val;
            if(mini>val)mini=val;
            if(node->left)q.push({node->left,(2*val)+1});
            if(node->right)q.push({node->right,(2*val)+2});
            
            }
            
            if(ans<maxi-mini+1) ans=maxi-mini+1;
            
            
        }
        return ans;
        
    }
};