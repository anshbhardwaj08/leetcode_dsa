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

    void helper(TreeNode* root,vector<int> &v){
        if(root==NULL) return ;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
    }
    bool isValidBST(TreeNode* root){
        
        vector<int>v;
        helper(root,v);
        if(v.size()==1) return true;
        vector<int>a;
        for(int i=0;i<v.size();i++){
            a.push_back(v[i]);
        }
        sort(a.begin(),a.end());

        for(int i=0;i<a.size();i++){
            if(v[i]!=a[i]) return false;
        }
        
        for(int i=0;i<v.size()-1;i++){
            if(v[i]==v[i+1]) return false;
        }
        
        return true;
        
    }
};