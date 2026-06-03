class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int target,vector<int>& coins){
        if(i==0){
            if(target%coins[i]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int not_take=f(i-1,target,coins);
        int take=0;
        if(target>=coins[i]){
            take=f(i,target-coins[i],coins);
        }
        return dp[i][target]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        dp.clear();
        dp.resize(coins.size(),vector<int>(amount+1,-1));

        
        int ans=f(coins.size()-1,amount,coins);
        
        return ans;
    }// just fo rhte tabulation thing the base case will look like 
    // for(int i=0;i<=amount;i++){
    // //      if(target%coins[i]==0){
    //             dp[0][i]= target/coins[i];
    //         }
    //         else{
    //             dp[0][i]= 1e9;
    //         }
    //}
    
};