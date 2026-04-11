class Solution {
public:
    vector<vector<int>>dp;
    int f(int ind,int prev,vector<int>&nums){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int len=0+f(ind+1,prev,nums);
        if(prev==-1 || nums[ind]>nums[prev]){
            len=max(len,1+f(ind+1,ind,nums));
        }
        return dp[ind][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.clear();
        dp.resize(n+1,vector<int>(n+1,-1));
        int ans=f(0,-1,nums);
        return ans;

    }
};