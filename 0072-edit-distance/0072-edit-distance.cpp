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
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    int take=dp[i-1][j-1];
                    dp[i][j]=take;
                }
                else{
                    dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                }
                
            }
        }
        return dp[n][m];
        // int ans=solve(n-1,m-1,s,t);
        // return ans;
    }
};