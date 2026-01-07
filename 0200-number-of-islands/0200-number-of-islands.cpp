class Solution {
public:

    void dfs(vector<vector<char>>& grid,int cr,int cc,char r, char original){
        int m=grid.size();
        int n=grid[0].size();
        if(cr<0||cr>m-1||cc<0||cc>n-1){
            return ;
        }
        if(grid[cr][cc]!=original){
            return ;
        }
        grid[cr][cc]=r;
        dfs(grid,cr-1, cc,r,original);
        dfs(grid,cr+1,cc,r,original);
        dfs(grid,cr,cc-1,r,original);
        dfs(grid,cr,cc+1,r,original);

    }
    int numIslands(vector<vector<char>>& grid) {
        
        
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,'2','1');
                    ans+=1;
                }

            }
        }
        return ans;
    }
};