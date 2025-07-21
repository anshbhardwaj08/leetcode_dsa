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

    vector<TreeNode*>arrange(TreeNode* root,vector<TreeNode*>&ans){
        if(root==NULL) return ans;
        ans.push_back(root);
        arrange(root->left,ans);
        arrange(root->right,ans);
        return ans;
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*>ans;
        vector<TreeNode*>a=arrange(root,ans);

        int n=a.size();
        for(int i=0;i<n-1;i++){
            a[i]->right=a[i+1];
            a[i]->left=NULL;
        }

    }
};