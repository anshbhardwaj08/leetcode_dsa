class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int m= board.size();
        int n= board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && board[i][j]=='O'){
                    board[i][j]='#';
                    q.push({i,j});
                }
                if(j==0 && board[i][j]=='O'){
                    board[i][j]='#';
                    q.push({i,j});
                }
                if(i==m-1 && board[i][j]=='O'){
                    board[i][j]='#';
                    q.push({i,j});
                }
                if(j==n-1 && board[i][j]=='O'){
                    board[i][j]='#';
                    q.push({i,j});
                }
            }
        }

        while(q.size()!=0){
            auto cell = q.front();
            q.pop();
            int a=cell.first;
            int b=cell.second;
            
            for(int d=0;d<4;d++){
                int nr=a+dir[d][0];
                int nc=b+dir[d][1];
                if(nr<0||nr>=m||nc<0||nc>=n) continue;
                if(board[nr][nc]=='X' || board[nr][nc]=='#') continue;
                board[nr][nc]='#';
                q.push({nr,nc});
            }
         
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};