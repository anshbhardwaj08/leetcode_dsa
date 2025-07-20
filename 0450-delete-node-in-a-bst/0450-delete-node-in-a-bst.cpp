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

    TreeNode* inos(TreeNode* root){
        TreeNode* pred=root->left;
        while(pred->right!=NULL){
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(root->val==key){
            // if leaf node 
            if(root->right==NULL && root->left==NULL) return NULL;

            // if 1 child 
            if( root->right==NULL || root->left==NULL){
                if(root->right!=NULL){
                    return root->right;
                }
                else{
                    return root->left;
                }
            }
            // if 2 child
            if( root->right!=NULL && root->left!=NULL){
                TreeNode* temp=inos(root);
                root->val=temp->val;
                root->left=deleteNode(root->left,temp->val);
            }
        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        if(root->val<key){
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};