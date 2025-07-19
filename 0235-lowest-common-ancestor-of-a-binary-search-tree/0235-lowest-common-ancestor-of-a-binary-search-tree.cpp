/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void helper(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &temp){
        if(p->val>=root->val && q->val<=root->val){
            temp=root;
            return ;
        } 
        else if(p->val<=root->val && q->val>=root->val){
            temp=root;
            return;
        } 

        else if(p->val<root->val && q->val<root->val){
            helper(root->left,p,q,temp);
        }
        else{
            helper(root->right,p,q,temp);
        }


   }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp=NULL;
        helper(root,p,q,temp);
        return temp;
    }
};