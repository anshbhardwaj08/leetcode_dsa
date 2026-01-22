class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        if(grid[0][0]!=0) return -1;
        if(grid[n-1][m-1]!=0) return -1;
        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        q.push({0,0});
        
        
        while(q.size()!=0){
            auto a=q.front();
            q.pop();
            int r=a.first;
            int c=a.second;
            if(r==n-1&& c==m-1){
                return dist[n-1][m-1]+1;
            }
            for(int d=0;d<8;d++){
                int nr=r+dir[d][0];
                int nc=c+dir[d][1];
                if(nr<0||nr>n-1||nc<0||nc>m-1){
                    continue;
                }
                if(grid[nr][nc]!=0){
                    continue;
                }
                if(dist[nr][nc]==INT_MAX){
                    q.push({nr,nc});
                    
                    dist[nr][nc]=dist[r][c]+1;
                }

            }
        }
        return -1;

    }
};