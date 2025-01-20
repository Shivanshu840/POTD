class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void Union(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);
        if (x_par == y_par) return; // Already in the same component
        
        // Union by rank
        if (rank[x_par] > rank[y_par]) {
            parent[y_par] = x_par;
        } else if (rank[y_par] > rank[x_par]) {
            parent[x_par] = y_par;
        } else {
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        // Map rows and columns into unique indices
        unordered_set<int> indices; 
        for (auto& stone : stones) {
            indices.insert(stone[0]);
            indices.insert(stone[1] + 10001); // Offset for columns
        }

        // Initialize DSU
        parent.resize(20002);
        rank.resize(20002, 0);
        for (int i = 0; i < 20002; ++i) parent[i] = i;

        // Union rows and columns
        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001; // Offset for columns
            Union(row, col);
        }

        // Count connected components
        unordered_set<int> uniqueParents;
        for (auto& stone : stones) {
            uniqueParents.insert(find(stone[0])); // Row parent
            uniqueParents.insert(find(stone[1] + 10001)); // Column parent
        }

        // Total stones - number of connected components
        return n - uniqueParents.size();
    }
};
