class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        } else if (rank[a] > rank[b]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Step 1: create all edges
        vector<vector<int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cost = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, cost});
            }
        }

        // Step 2: sort edges by cost
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        // Step 3: initialize DSU
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Step 4: Kruskal
        int minCost = 0;
        int edgesUsed = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            if (find(u) != find(v)) {
                unite(u, v);
                minCost += cost;
                edgesUsed++;
            }

            if (edgesUsed == n - 1)
                break;
        }

        return minCost;
    }
};
