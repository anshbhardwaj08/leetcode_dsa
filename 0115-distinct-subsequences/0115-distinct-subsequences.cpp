class Solution {
public:
    vector<vector<double>>dp;
    int solve(string s,string t,int i, int j ){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // if(i==0 || j==0){
        //     if(a[i]==s[j]){
        //         return 1;
        //     }
        //     else{
        //         return 0;
        //     }
        // }
        
        if(s[i]==t[j]){
            int not_take=solve(s,t,i-1,j);
            int take=0;
            take=solve(s,t,i-1,j-1);
            return dp[i][j]=not_take+take;
        }
         return dp[i][j] = solve(s,t,i-1,j);
        
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.clear();
    
        dp.resize(n+1,vector<double>(m+1,0));
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s[i-1]==t[j-1]){
                    
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
                
            }
        }
        return (int)dp[n][m];
        // int ans=solve(s,t,n-1,m-1);
        // return ans;

    }
};