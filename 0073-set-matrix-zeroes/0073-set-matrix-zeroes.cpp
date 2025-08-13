class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        typedef pair<int,int>p;
        stack<p>st;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    st.push({i,j});
                }
            }
        }
        while(st.size()!=0){
            int a=st.top().first;
            int b=st.top().second;
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[0].size();j++){
                    if(i==a || j==b){
                        matrix[i][j]=0;
                    }
                }
            }
            st.pop();
        }
        
        

    }
};