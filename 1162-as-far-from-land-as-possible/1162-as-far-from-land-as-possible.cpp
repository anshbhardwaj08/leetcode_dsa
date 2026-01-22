class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        
        // Push all land cells as BFS sources
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        // Edge case: no land or no water
        if (q.empty() || q.size() == n * m) return -1;
        
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int ans = 0;
        
        // Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto &d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if (dist[nr][nc] != -1) continue;
                
                dist[nr][nc] = dist[r][c] + 1;
                ans = max(ans, dist[nr][nc]);
                q.push({nr, nc});
            }
        }
        
        return ans;
    }
};
