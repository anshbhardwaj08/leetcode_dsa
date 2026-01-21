class Solution {
public:
    
    queue<int>q;
    
    bool bfs(int src, vector<vector<int>>& graph, int n,vector<int>& color){
        q.push(src);
        color[src]=1;
        while(q.size()!=0){
            int a =q.front();
            q.pop();
            for(auto neighbour: graph[a]){
                if(color[neighbour]==-1){
                    if(color[a]==1){
                        color[neighbour]=2;
                        q.push(neighbour);
                    }
                    else{
                        color[neighbour]=1;
                        q.push(neighbour);
                    }
                }
                if(color[neighbour]==color[a]){
                    return false;
                }
            }

        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>color(n,-1);
        
        
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,graph,n,color)==false) return false;
            }
        }
        return true;
    }
};