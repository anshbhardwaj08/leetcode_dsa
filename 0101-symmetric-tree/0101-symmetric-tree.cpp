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

    bool helper(TreeNode* root,TreeNode* l ,TreeNode* r){
        if(l==NULL && r==NULL) return true;
        if(l==NULL || r==NULL) return false;
        if(l->val!=r->val) return false;
        
        return helper(root,l->left,r->right) && helper(root,l->right,r->left);
        
        

    }

    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->left==NULL || root->right==NULL){
            return false;
        }
        TreeNode* l=root;
        TreeNode* r=root;
        bool ans=helper(root,l->left,r->right);
        if(ans==false) return false;
        return true;
    }
};