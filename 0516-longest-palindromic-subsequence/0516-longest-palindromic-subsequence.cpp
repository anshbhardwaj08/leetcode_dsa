class Solution {
public:
    vector<vector<int>>dp;
    // int f(string s , string t,int i,int j){
    //     if(i<0|| j<0){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s[i]==t[j]){
    //         return dp[i][j]=1+f(s,t,i-1,j-1);
    //     }
    //     return dp[i][j]=max(f(s,t,i,j-1),f(s,t,i-1,j));

    // }
    int longestPalindromeSubseq(string s) {
        dp.clear();
        dp.resize(s.size()+1,vector<int>(s.size()+1,-1));
        string t=s;
        reverse(t.begin(),t.end());
        // int ans=f(s,t,s.size()-1,s.size()-1);
        // return ans;
        for(int i=0;i<=s.size();i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=s.size();j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s.size()][s.size()];
        
    }
};