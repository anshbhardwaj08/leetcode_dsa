class Solution {
public:
    vector<vector<int>>dp;
    // int f(int i,int j,string s, string t){
    //     if(i<0||j<0){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s[i]==t[j]){
    //         return dp[i][j]=1+f(i-1,j-1,s,t);
    //     }
    //     return dp[i][j]=max(f(i-1,j,s,t),f(i,j-1,s,t));

    // }
    int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.clear();
        dp.resize(n+1,vector<int>(m+1,-1));
        // int ans=f(n-1,m-1,s,t);
        //return ans;
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];

    }
};