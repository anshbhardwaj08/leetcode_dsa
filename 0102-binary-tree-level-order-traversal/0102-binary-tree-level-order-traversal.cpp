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
    void nthlevel(TreeNode* root,int curr , int &level, vector<int>& v){
        if(root==NULL) return ;
        if(curr==level){
            v.push_back(root->val);
            return ;
        }
        nthlevel(root->left,curr +1,level,v);
        nthlevel(root->right,curr +1,level,v);

    }

    void levelorder(TreeNode*root,vector<vector<int>>& ans){
        int n=levels(root);
        if(root==NULL ) return ;
        for(int i=1;i<=n;i++){
            vector<int>v;
            nthlevel(root,1,i,v);
            ans.push_back(v);

        }
    }

    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right)); 
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        levelorder(root,ans);
        return ans;


        
    }
};