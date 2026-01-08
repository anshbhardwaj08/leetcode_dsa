class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

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

                if(dist[nr][nc] > dist[r][c] + 1){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return dist;
    }
};
