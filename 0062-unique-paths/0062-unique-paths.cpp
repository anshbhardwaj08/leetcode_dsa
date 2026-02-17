class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=helper(grid,i,j+1,dp)+helper(grid,i+1,j,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,1));
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(grid,0,0,dp);

    }
};