class Solution {
public:
    vector<vector<vector<int>>> dp;

    int f(int i, int j, int cost, vector<vector<int>>& grid, int k){
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n) return INT_MIN;
        if(cost > k) return INT_MIN;

        if(dp[i][j][cost] != -1)
            return dp[i][j][cost];

        int newCost = cost + (grid[i][j] != 0);

        if(i == m-1 && j == n-1){
            if(newCost > k) return dp[i][j][cost] = INT_MIN;
            return dp[i][j][cost] = grid[i][j];
        }

        int right = f(i, j+1, newCost, grid, k);
        int down  = f(i+1, j, newCost, grid, k);

        int best = max(right, down);

        if(best == INT_MIN)
            return dp[i][j][cost] = INT_MIN;

        return dp[i][j][cost] = grid[i][j] + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        int ans = f(0, 0, 0, grid, k);
        return (ans < 0 ? -1 : ans);
    }
};