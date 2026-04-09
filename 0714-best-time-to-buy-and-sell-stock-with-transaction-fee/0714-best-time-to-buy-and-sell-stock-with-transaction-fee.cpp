class Solution {
public:
    vector<vector<int>> dp;

    int f(int ind,int buy,vector<int>& prices,int fee){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        if(buy==1){
            return dp[ind][buy]= max(-prices[ind]+f(ind+1,0,prices,fee),f(ind+1,1,prices,fee));
        }
        
            return dp[ind][buy]= max(prices[ind]-fee+f(ind+1,1,prices,fee),f(ind+1,0,prices,fee));
        
        

        

    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        int ans=f(0,1,prices,fee);
        if(ans>0){
            return ans;
        }
        else{
            return 0;
        }
    }
};