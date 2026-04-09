class Solution {
public:
    vector<vector<vector<int>>> dp;

    int f(int ind,int buy,int cap,vector<int>& prices){
        if(ind==prices.size()|| cap==0){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        if(buy==1){
            return dp[ind][buy][cap]= max(-prices[ind]+f(ind+1,0,cap,prices),f(ind+1,1,cap,prices));
        }
        
            return dp[ind][buy][cap]= max(prices[ind]+f(ind+1,1,cap-1,prices),f(ind+1,0,cap,prices));
        
        

        

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        int ans=f(0,1,2,prices);
        if(ans>0){
            return ans;
        }
        else{
            return 0;
        }
    }
};