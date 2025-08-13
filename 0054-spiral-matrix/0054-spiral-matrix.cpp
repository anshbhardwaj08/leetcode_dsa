class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();// rows
        int n=matrix[0].size(); // columns
        int minr=0;
        int maxr=m-1;
        int minc=0;
        int maxc=n-1;
        int total=n*m;
        int count=0;
        vector<int>ans;
        while(minr<=maxr && minc<=maxc){
            for(int i=minc;i<=maxc && count<total ;i++){
                
                ans.push_back(matrix[minr][i]);
                count+=1;
            }
            minr++;
            for(int j=minr;j<=maxr  && count<total;j++){
                ans.push_back(matrix[j][maxc]);
                count+=1;
            }
            maxc--;
            for(int i=maxc;i>=minc  && count<total;i--){
                ans.push_back(matrix[maxr][i]);
                count+=1;
            }
            maxr--;
            for(int j=maxr;j>= minr && count<total;j--){
                ans.push_back(matrix[j][minc]);
                count+=1;
            }
            minc++;
        }
        return ans;

    }
};