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

    void build(TreeNode* root,queue<int> &q){
        if(root==NULL) return ;
        build(root->left,q);
        root->val=q.front();
        q.pop();
        build(root->right,q);

    }
    void helper(TreeNode* root,vector<int> &v){
        if(root==NULL) return ;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);

    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>v;
        helper(root,v);
        queue<int>q;
        int i=0;
        while(i<v.size()){
            int j=i+1;
            int sum=v[i];
            while(j<v.size()){
                sum=sum+v[j];
                j++;
            }
            q.push(sum);
            i++;
        }
        build(root,q);

        return root;



        
    }
};