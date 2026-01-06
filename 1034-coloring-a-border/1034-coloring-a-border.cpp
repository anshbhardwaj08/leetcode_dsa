class Solution {
public:
    vector<pair<int,int>>a;
    void dfs(vector<vector<int>>& grid, int cr, int cc, int initialcolor, int color){
        int m= grid.size(); 
        int n= grid[0].size();
        if(cr>=m||cr<0||cc>=n||cc<0){
            return ;
        }
        if(grid[cr][cc]==color) return;
        if(initialcolor!=grid[cr][cc]) return ;
        grid[cr][cc]=-color;
        
        dfs(grid,cr-1,cc,initialcolor,color);
        dfs(grid,cr+1,cc,initialcolor,color);
        dfs(grid,cr,cc-1,initialcolor,color);
        dfs(grid,cr,cc+1 ,initialcolor,color);
        if(!(cc==0 || cr==0 ||cr==m-1||cc==n-1|| grid[cr+1][cc]!=-color|| grid[cr-1][cc]!=-color|| grid[cr][cc-1]!=-color|| grid[cr][cc+1]!=-color)){
            a.push_back({cr,cc});
        }
        
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int in=grid[row][col];
        if(in==color) return grid;
        dfs(grid, row,col,grid[row][col],color);
        for(auto i: a){
            int x=i.first;
            int y=i.second;
            grid[x][y]=in;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0){
                    grid[i][j]*=-1;
                }
            }
        }
        return grid;
    }
};