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
        int not_take=0+f(ind+1,prev,nums);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev]){
            take=1+f(ind+1,ind,nums);
        }
        return dp[ind][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        dp.clear();
        dp.resize(n+1,vector<int>(n+1,0));
        dp[n][n]=0;
        for(int ind =n-1;ind>=0;ind--){
            for(int prev=ind;prev>=-1;prev--){
                int not_take=dp[ind+1][prev+1];
                int take=0;
                if(prev==-1 || arr[ind]>arr[prev]){
                    take=1+dp[ind+1][ind+1];
                }
                dp[ind][prev+1]=max(take,not_take);
            }
        }
        return dp[0][0];
        

    }
};