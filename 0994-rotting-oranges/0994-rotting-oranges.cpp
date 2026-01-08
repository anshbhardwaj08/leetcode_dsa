class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fo=0;
        int min=0;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        for(int i=0;i< grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fo++;
                }
            }
        }
        q.push({-1,-1});
        while(q.size()!=0){
            auto cell =q.front();
            q.pop();
            if(cell.first==-1 and cell.second==-1){
                min++;
                if(q.size()!=0){
                    q.push({-1,-1});
                }
                else{
                    break;
                }

            }
            else{
                int a =cell.first;
                int b =cell.second;
                for(int d=0;d<4;d++){
                    int newa=a+dir[d][0];
                    int newb=b+dir[d][1];
                    if(newa<0 || newa>=grid.size() || newb<0 || newb>=grid[0].size())
    continue;
if(grid[newa][newb]==2 || grid[newa][newb]==0)
    continue;

                    fo--;
                    grid[newa][newb]=2;
                    q.push({newa,newb});
                }
            }
        }
        return (fo==0) ? min-1 : -1;
    }
};