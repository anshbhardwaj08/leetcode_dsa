class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> g;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                g.push_back(grid[i][j]);
            }
        }
        sort(g.begin(),g.end());
        int i=1;
        int a=g[0]%x;
        while(i<g.size()){
            if(a!=g[i]%x){
                return -1;
            }
            else{
                i++;

            }
        }
        int b=g.size()/2;
        int median=g[b];
        i=0;
        int j=g.size()-1;
        int cnt=0;
        // while(i<b || j>b){
        //     while(g[i]!=median && i<b){
        //         g[i]+=x;
        //         cnt++;
        //     }
        //     i++;
        //     while(g[j]!=median && j>b){
        //         g[j]-=x;
        //         cnt++;
        //     }
        //     j--;
        // }
        while(i<b){
            cnt+=(median-g[i])/x;
            i++;
        }
        while(j>b){
            cnt+=(g[j]-(median))/x;
            j--;
        }
        return cnt;

    }
};