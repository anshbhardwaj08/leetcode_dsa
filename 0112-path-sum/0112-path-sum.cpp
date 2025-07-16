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

    void helper(TreeNode* root,vector<vector<int>> &ans,int targetsum,int sum,vector<int>v ){
        if(root==NULL) return ;
        sum=sum+root->val;
        v.push_back(root->val);
        // if(abs(sum)<abs(targetsum)){
        //     v.push_back(root->val);
        // }
        if((sum)==(targetsum) && (root->left==NULL && root->right==NULL)){
            
            ans.push_back(v);
            return ;
        }
        // if(abs(sum)>abs(targetsum) || (abs(sum)==abs(targetsum) && (root->left!=NULL && root->right!=NULL))){
        //     return;
        // }
        helper(root->left,ans,targetsum,sum,v);
        helper(root->right,ans,targetsum,sum,v);
    }
    bool hasPathSum(TreeNode* root, int targetsum) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(root,ans,targetsum,0,v);
        if(ans.size()==0) return false;
        return true;
    }
};