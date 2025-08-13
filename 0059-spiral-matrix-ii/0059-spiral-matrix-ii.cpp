class Solution {
public:
    vector<vector<int>> generateMatrix(int a) {
        vector<vector<int>>ans(a,vector<int>(a));
        // vector<vector<int>>res(a,vector<int>(a));
        int m=ans.size();// rows
        int n=ans[0].size(); // columns
        int minr=0;
        int maxr=m-1;
        int minc=0;
        int maxc=n-1;
        int total=n*m;
        int count=0;
        int k=1;
        
        while(minr<=maxr && minc<=maxc && k<=n*n){
            for(int i=minc;i<=maxc && count<total ;i++){
                
                ans[minr][i]=k;
                count+=1;
                k++;
            }
            minr++;
            for(int j=minr;j<=maxr  && count<total;j++){
                ans[j][maxc]=k;
                count+=1;
                k++;
            }
            maxc--;
            for(int i=maxc;i>=minc  && count<total;i--){
                ans[maxr][i]=k;
                count+=1;
                k++;
            }
            maxr--;
            for(int j=maxr;j>= minr && count<total;j--){
                ans[j][minc]=k;
                count+=1;
                k++;
            }
            minc++;
        }
        return ans;

        // for(int i=0;i<ans.size();i++){
        //     for(int j=0;j<ans[0].size();j++){
        //         res[i][j]=ans[]
        //     }
        // }
    }
};