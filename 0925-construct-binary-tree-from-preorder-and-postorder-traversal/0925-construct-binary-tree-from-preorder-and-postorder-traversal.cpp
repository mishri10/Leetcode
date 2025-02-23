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
    TreeNode* helper(int preStart, int preEnd, int postStart, 
            vector<int>& preorder, unordered_map<int,int>& PostorderMap){

                if(preStart>preEnd)
                    return NULL;
                if(preStart==preEnd)
                    return new TreeNode(preorder[preStart]);


                TreeNode* node= new TreeNode(preorder[preStart]);
                int leftSubtree= PostorderMap[preorder[preStart+1]]-postStart
                                                                            +1;
                node->left=helper(preStart+1,preStart+leftSubtree,postStart,
                preorder,PostorderMap);

                node->right=helper(preStart+leftSubtree+1,preEnd, postStart
                +leftSubtree,preorder,PostorderMap);

                return node;
            }



    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>PostorderMap;
        int n=postorder.size();
        for(int i=0; i<postorder.size();i++){
            PostorderMap[postorder[i]]=i;
        }

        return helper(0,n-1,0,preorder,PostorderMap);
    }
};