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

    void helper(TreeNode* temp, TreeNode* root){
        if(root->left==NULL && root->right==NULL) return ;
        if(root->right==NULL){
            temp->left=NULL;
        }
        if(root->left==NULL){
            temp->right=NULL;
        }
        if(root->right!=NULL) {
            temp->left=new TreeNode(root->right->val);
            helper(temp->left,root->right);
        }
        if(root->left!=NULL){

            temp->right=new TreeNode(root->left->val);
        
            helper(temp->right,root->left);
        }
        
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        TreeNode* a= new TreeNode(root->val);
        TreeNode * temp=a;
        helper(temp,root);
        return a;
        
    }
};