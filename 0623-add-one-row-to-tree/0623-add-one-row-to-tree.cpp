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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        queue<TreeNode*>q;
        q.push(root);
        int target=depth-1;
        int deep=1;
        
        while(!q.empty()){
            
            if(deep==target){
                int n=q.size();
                
                for(int i=0;i<n;i++){
                    TreeNode* node=q.front();
                    q.pop();
                    TreeNode* existleft= node->left;
                    TreeNode* existright=node->right;
                    TreeNode* newleft= new TreeNode(val);
                    TreeNode* newright= new TreeNode(val);
                    
                    node->left=newleft;
                    node->right=newright;
                    
                    newleft->left=existleft;
                    newright->right=existright;
                }
                return root;
            }
            
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
            }
            deep++;
        }
        
        return root;
        
    }
};