class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c,int area){

        int n=grid.size();

        int m=grid[0].size();

        if(r<0 ||r>n-1||c<0||c>m-1){
            return area;
        }
        if(grid[r][c]==0 || grid[r][c]==-1){
            return area;
        }
        grid[r][c]=-1;
        area+=1;

        area=dfs(grid,r-1,c,area);
        area=dfs(grid,r+1,c,area);
        area=dfs(grid,r,c-1,area);
        area=dfs(grid,r,c+1,area);
        return area;
       

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int maxarea=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=0;
                    maxarea=max(maxarea,dfs(grid,i,j,area));
                    ans++;
                }
            }
        }
        return maxarea;
    }
};