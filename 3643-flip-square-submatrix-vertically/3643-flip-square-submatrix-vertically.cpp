class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),0));
        int n=grid.size();
        int m=grid[0].size();
        int right=x+k-1;//j
        int down=y+k-1;// i
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==x && j==y){
                    for(int a=i;a<k+i;a++){
                        for(int b=j;b<k+j;b++){
                            ans[a][b]=grid[k-1-a+2*i][b];
                        }
                    }
                }
                if(ans[i][j]!=0){
                    continue;
                }
                
                ans[i][j]=grid[i][j];
                
            }
        }
        return ans;

    }
};