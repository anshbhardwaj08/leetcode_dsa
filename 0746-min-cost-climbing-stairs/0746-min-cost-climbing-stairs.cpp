class Solution {
public:
    int helper(vector<int>& dp,vector<int>& cost,int i){
        
        if(i==0 || i==1){
            return cost[i];
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        return dp[i]=cost[i]+min(helper(dp,cost,i-1),helper(dp,cost,i-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(helper(dp,cost,n-1),helper(dp,cost,n-2));
    }
};