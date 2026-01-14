class Solution {
public:
    // vector<int> parent(n,0);
    // vector<int>size(7,1);
    // for(int i=0;i<parent.size();i++){
    //     parent[i]=i;
    // }

    void addedge(vector<vector<int>>& graph, int a, int b){
        graph[a].push_back(b);
        graph[b].push_back(a);
        return;
    }
    // int find(int x){
    //     if(parent[x]==x) return x;
    //     return parent[x]=find(parent[x]);
    // }
    // void union(int m,int n){
    //     int m=find(m);
    //     int n=find(n);
    //     if(m==n) return ;
    //     if(size[m]>=size[n]){
    //         size[m]+=size[n];
    //         parent[n]=m;
    //     }
    //     else{
    //         size[n]+=size[m];
    //         parent[m]=n;
    //     }
    // }
    void dfs(int i,vector<vector<int>>& graph,int &count, vector<bool>& visited){
        visited[i]=true;
        count++;
        for(auto neighbour: graph[i]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                dfs(neighbour,graph, count, visited);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int s=edges.size();
        for(int i=0;i<s;i++){
            
                int a=edges[i][0];
                int b=edges[i][1];
                addedge(graph, a,b);
            
        }
        vector<bool>visited(n,false);
        long long ans=0;
        long long remaining =n;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int componentsize=0;
                dfs(i,graph,componentsize,visited);
                ans=ans+componentsize*(remaining-componentsize);
                remaining-=componentsize;
            }
        }
        return ans;
        



    }
};