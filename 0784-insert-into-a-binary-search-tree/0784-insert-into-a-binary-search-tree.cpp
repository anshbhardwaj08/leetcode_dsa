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
    void helper(TreeNode* root, TreeNode* &temp){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(root->val>temp->val){
                root->left=temp;
                return ;
            }
            root->right=temp;
            return ;

        }
        if(root->left==NULL && temp->val<root->val){
            root->left=temp;
            return;
        }
        if(root->right==NULL && temp->val>root->val){
            root->right=temp;
            return;
        }
        
        if(root->val>temp->val) helper(root->left,temp);
        if(root->val<temp->val) helper(root->right,temp);
        
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* temp=new TreeNode(val);
        if(root==NULL) return temp;
        helper(root,temp);
        
        return root;
    }
};