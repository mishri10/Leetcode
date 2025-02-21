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
class FindElements {
public: 

    void preorder(TreeNode* node,unordered_set<int>& s){
        if(node==NULL)
            return;
        
        if(node->left!=NULL){
            s.insert(2*(node->val)+1);
            node->left->val=(2*(node->val)+1);}
        if(node->right!=NULL){
            s.insert(2*(node->val)+2);
            node->right->val=(2*(node->val)+2);
        }
           

        preorder(node->left,s);
        preorder(node->right,s);
        }
    

    unordered_set<int>s;
    FindElements(TreeNode* root) {
        s.insert(0);
        root->val=0;
        preorder(root,s);
    }
    
    bool find(int target) {
        return s.count(target)!=0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */