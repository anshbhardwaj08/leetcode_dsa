class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& v,int i, int j ){
        if(i<0 || j<0 ){
            return 0;
        }
        if(v[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        
        int up=solve(v,i-1,j);
        int left=solve(v,i,j-1);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m=v.size(); 
        int n=v[0].size(); 
        dp.clear();
        dp.resize(m,vector<int>(n,-1));
        if(v[0][0]==1 && m==1 && n==1){
            return 0;
        }
        int ans=solve(v,m-1,n-1);
        return ans;

    }
};