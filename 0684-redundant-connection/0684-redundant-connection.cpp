class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void dsu(int x, int y) {
        int parX = find(x);
        int parY = find(y);

        if (parX == parY) return;

        if (rank[parX] > rank[parY]) {
            parent[parY] = parX;
        } else if (rank[parY] > rank[parX]) {
            parent[parX] = parY;
        } else {
            parent[parX] = parY;
            rank[parY]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1); // Fix: Use n+1 for 1-based indexing
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) { 
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            if (find(u) == find(v)) { 
                return {u, v};
            }
            dsu(u, v);
        }

        return {}; // Should never reach here in a valid input
    }
};
