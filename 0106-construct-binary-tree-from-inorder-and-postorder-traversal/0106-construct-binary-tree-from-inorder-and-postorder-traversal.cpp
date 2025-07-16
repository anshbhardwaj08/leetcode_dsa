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

    TreeNode* helper(vector<int> &pos,int poslo,int poshi,vector<int> &in,int inlo,int inhi){
        if(inlo>inhi) return NULL;
        
        TreeNode* root=new TreeNode(pos[poshi]);
        if(inlo==inhi){
            return root;
        }
        int i=inlo;
        while(i<=inhi){
            if(in[i]==pos[poshi]){
                break;
            };
            
            i++;
        }

        int leftcount=i-inlo;
        int rightcount=inhi-i;
        root->left=helper(pos, poslo, poslo+leftcount-1,in,inlo,i-1) ;
        root->right=helper(pos, poslo+leftcount, poshi-1,in,i+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& pos) {
        
        int n=pos.size();
        TreeNode* temp=helper(pos,0,n-1,in,0,n-1);
        return temp;

    }
};