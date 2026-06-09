class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i , int j,string& s, string& t){
        if(j<0){
            return i+1;
        }
        if(i<0){
            return j+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
            int take=solve(i-1,j-1,s,t);
            return dp[i][j]=take;
        }
        return dp[i][j]=1+min(min(solve(i-1,j,s,t),solve(i,j-1,s,t)),solve(i-1,j-1,s,t));
    }
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.clear();
        dp.resize(n,vector<int>(m,-1));
        int ans=solve(n-1,m-1,s,t);
        return ans;
    }
};