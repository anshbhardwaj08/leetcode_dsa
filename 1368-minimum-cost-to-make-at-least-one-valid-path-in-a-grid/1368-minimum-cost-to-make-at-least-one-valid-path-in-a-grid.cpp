class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        pq.push({0,0,0});
        dist[0][0]=0;
        while(pq.size()!=0){
            auto a=pq.top();
            pq.pop();
            int cost=a[0];
            int r=a[1];
            int c=a[2];
            if(r==n-1 && c==m-1 ){
                return cost;
            }
            if(cost>dist[r][c]){
                continue;
            }
            
            for(int d=0;d<4;d++){
                int nr=r+dir[d][0];
                int nc=c+dir[d][1];
                if(nr<0 || nr>=n || nc<0 || nc>=m){
                    continue;
                }
                
                int newcost=cost + (grid[r][c]-1==d?0:1);
                if(newcost<dist[nr][nc]){
                    dist[nr][nc]=newcost;
                    pq.push({newcost,nr,nc});
                }




            }
        }
        return dist[n-1][m-1];
    }
};