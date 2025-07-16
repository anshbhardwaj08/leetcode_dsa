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

    TreeNode* helper(vector<int> &pre,int prelo,int prehi,vector<int> &in,int inlo,int inhi){
        if(prelo>prehi) return NULL;
        int i=inlo;
        TreeNode* root=new TreeNode(pre[prelo]);
        if(prelo==prehi){
            return root;
        }
        while(i<=inhi){
            if(in[i]==pre[prelo]){
                break;
            };
            
            i++;
        }

        int leftcount=i-inlo;
        int rightcount=inhi-i;
        root->left=helper(pre, prelo+1, prelo+leftcount,in,inlo,i-1) ;
        root->right=helper(pre, prelo+leftcount+1, prehi,in,i+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        TreeNode* temp=helper(pre,0,n-1,in,0,n-1);
        return temp;
    }
};