class Solution {
public:

    void dfs(vector<vector<int>>& grid,int r,int c){
        int m=grid.size();
        int n=grid[0].size();
        if(r<0||c<0||c>n-1||r>m-1){
            return ;
        }
        if(grid[r][c]==0 || grid[r][c]==-1) return ;
        grid[r][c]=-1;
        dfs(grid,r-1,c);
        dfs(grid,r+1,c);
        dfs(grid,r,c-1);
        dfs(grid,r,c+1);
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        queue<pair<int,int>> st;
        int u=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    u++;
                    break;
                }
            }
            if(u==1){
                break;
            }
        }
        

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==-1){

                    st.push({i,j});
            
                }
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        while(q.size()!=0){
            auto cell =q.front();
            q.pop();
            int a=cell.first;
            int b=cell.second;
            for(int d=0;d<4;d++){
                int nr=a+dir[d][0];
                int nc=b+dir[d][1];
                if(nr<0||nr>=m||nc<0||nc>=n) continue;
                if(grid[nr][nc]==1) continue;
                if(grid[nr][nc]==-1) continue;
                if(grid[nr][nc]==0){
                    grid[nr][nc] = grid[a][b] + 1;
                    q.push({nr, nc});
                }



            }

        }   
        int dist=INT_MAX;
         while(st.size()!=0){
            auto cell =st.front();
            st.pop();
            int a=cell.first;
            int b=cell.second;
            for(int d=0;d<4;d++){
                int nr=a+dir[d][0];
                int nc=b+dir[d][1];
                if(nr<0||nr>=m||nc<0||nc>=n) continue;
                
                if(grid[nr][nc]==-1) continue;
                if(grid[nr][nc]==0) continue;
                dist=min(dist,grid[nr][nc]);



            }

        }    
        return dist-1;    

        
    }
};