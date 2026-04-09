class Solution {
public:
    vector<vector<int>> dp;

    int f(int ind,int buy,vector<int>& prices){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        if(buy==1){
            return dp[ind][buy]= max(-prices[ind]+f(ind+1,0,prices),f(ind+1,1,prices));
        }
        
            return dp[ind][buy]= max(prices[ind]+f(ind+1,1,prices),f(ind+1,0,prices));
        
        

        

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        int ans=f(0,1,prices);
        if(ans>0){
            return ans;
        }
        else{
            return 0;
        }
    }
};