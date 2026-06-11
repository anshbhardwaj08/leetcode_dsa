class Solution {
public:
    #define mod 1000000007

    int maxDepth = 0;

    void dfs(int node, int parent, int depth, vector<vector<int>>& adj){

        maxDepth = max(maxDepth, depth);

        for(auto child : adj[node]){
            if(child == parent)
                continue;

            dfs(child,node,depth+1,adj);
        }
    }

    long long binpow(long long a,long long b){

        long long ans=1;

        while(b){

            if(b&1)
                ans=(ans*a)%mod;

            a=(a*a)%mod;
            b/=2;
        }

        return ans;
    }


    int assignEdgeWeights(vector<vector<int>>& edges){

        int n=edges.size()+1;

        vector<vector<int>> adj(n+1);

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1,-1,0,adj);


        return binpow(2,maxDepth-1);
    }
};