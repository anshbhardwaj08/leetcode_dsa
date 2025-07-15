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

    void helper(TreeNode* root,long long targetsum,long long sum,int &ans ){
        if(root==NULL) return ;
        
        sum=sum+root->val;
        
        // if(abs(sum)<abs(targetsum)){
        //     v.push_back(root->val);
        // }
        if((sum)==(targetsum) ){
            ans=ans+1;
            
            // ans.push_back(v);
            
        }
        // if(abs(sum)>abs(targetsum) || (abs(sum)==abs(targetsum) && (root->left!=NULL && root->right!=NULL))){
        //     return;
        // }
        helper(root->left,targetsum,sum,ans);
        helper(root->right,targetsum,sum,ans);
    }
    int pathSum(TreeNode* root, int targetsum) {
        if(root==NULL) return 0;
       
        int ans=0;
        helper(root,(long long)targetsum,0,ans);
        return ans+ pathSum( root->left,targetsum) + pathSum( root->right, targetsum);
        

    }
};