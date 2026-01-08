class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        // Step 1: Push all water cells
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Step 2: Multi-source BFS
        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            int r = cell.first;
            int c = cell.second;

            for(int d = 0; d < 4; d++){
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if(height[nr][nc] == -1){
                    height[nr][nc] = height[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return height;
    }
};
