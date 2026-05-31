class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=solve(i-1,j);
        int left=solve(i,j-1);
        return dp[i][j]=up+left;


    }
    int uniquePaths(int m, int n) {
        dp.clear();
        dp.resize(m,vector<int>(n,-1));
        int ans=solve(m-1,n-1);
        return ans;
    }
};