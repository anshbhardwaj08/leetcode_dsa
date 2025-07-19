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
    
    TreeNode* helper(vector<int> &nums,int lo,int hi){
        if(lo>hi) return NULL;
        int mid=lo+(hi-lo)/2;
        TreeNode* temp=new TreeNode(nums[mid]);
        temp->left= helper(nums,lo,mid-1);
        temp->right=helper(nums,mid+1,hi);
        return temp;
    }

    void helper(TreeNode* root,vector<int> &nums){
        if(root==NULL) return ;
        helper(root->left,nums);
        nums.push_back(root->val);
        helper(root->right,nums);

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>nums;
        helper(root,nums);
        TreeNode* temp= helper(nums,0,nums.size()-1);
        return temp;

    }
};