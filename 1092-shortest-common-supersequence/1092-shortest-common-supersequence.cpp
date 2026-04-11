class Solution {
public:
    vector<vector<int>>dp;
    string shortestCommonSupersequence(string s, string t) {
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
        int len=dp[n][m];
        int l=n+m-len;
        int i=n;
        int j=m;
        string ans;
        int ind=l-1;
        for(int i=0;i<l;i++){
            ans.push_back('@');
        }
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans[ind]=s[i-1];
                i--;
                j--;
                ind--;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                ans[ind]=t[j-1];
                ind--;
                j--;
            }
            else{
                ans[ind]=s[i-1];
                ind--;
                i--;
            }
        }
         while(i > 0) {
            ans[ind--] = s[i - 1];
            i--;
        }

        while(j > 0) {
            ans[ind--] = t[j - 1];
            j--;
        }
        return ans;
    }
};