class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[0][0] = triangle[0][0];

        for(int i=1;i<n;i++){

            // left boundary
            dp[i][0] = dp[i-1][0] + triangle[i][0];

            // middle cells
            for(int j=1;j<i;j++){
                dp[i][j] = triangle[i][j] +
                           min(dp[i-1][j-1], dp[i-1][j]);
            }

            // right boundary
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }

        int ans = INT_MAX;

        for(int j=0;j<n;j++){
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};