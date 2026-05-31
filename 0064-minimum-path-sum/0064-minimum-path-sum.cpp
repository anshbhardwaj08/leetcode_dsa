class Solution {
public:
    vector<vector<int>>dp;
    // int solve(vector<vector<int>>& grid,int i,int j){
    //     if(i==0 && j==0){
    //         return grid[i][j];
    //     }
    //     if(i<0 || j<0){
    //         return INT_MAX;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     return dp[i][j]=grid[i][j]+min(solve(grid,i-1,j),solve(grid,i,j-1));
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp.clear();
        dp.resize(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        // first row
for(int j=1;j<n;j++){
    dp[0][j] = dp[0][j-1] + grid[0][j];
}

// first column
for(int i=1;i<m;i++){
    dp[i][0] = dp[i-1][0] + grid[i][0];
}
        
        // int ans=solve(grid, m-1, n-1);
        // return ans;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
        
    }
};