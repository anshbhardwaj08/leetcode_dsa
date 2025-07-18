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
    void helper(TreeNode* root,int a , TreeNode* &temp){
        if(root==NULL) return;
        if(root->val==a){
            temp=root;
            return;
        } 
        if(root->val>a) helper(root->left,a,temp);
        if(root->val<a) helper(root->right,a,temp);
        
    }


    TreeNode* searchBST(TreeNode* root, int a) {
        if(root==NULL) return NULL;
        TreeNode* temp=NULL;
        helper(root,a,temp);
        
        return temp;

    }
};