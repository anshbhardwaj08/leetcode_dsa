class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>>ans;
        for(int i=0;i<n+1; i++){
            vector<int>a(i+1);
            ans.push_back(a);

        }
        
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    ans[i][j]=1;
                }
                else{
                    ans[i][j]=ans[i-1][j] + ans[i-1][j-1];
                }
            }

        }
        vector<int>res;
        for(int i=0;i<ans.size();i++){
            if(i==n){
               res=ans[i];
               break;

            }
        }
        return res;


    }
};