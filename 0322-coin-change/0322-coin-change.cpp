class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int target,vector<int>& coins){
        if(i==0){
            if(target%coins[i]==0){
                return target/coins[i];
            }
            else{
                return 1e9;
            }
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int not_take=f(i-1,target,coins);
        int take=INT_MAX;
        if(target>=coins[i]){
            take=1+f(i,target-coins[i],coins);
        }
        return dp[i][target]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        
        int ans=f(coins.size()-1,amount,coins);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};