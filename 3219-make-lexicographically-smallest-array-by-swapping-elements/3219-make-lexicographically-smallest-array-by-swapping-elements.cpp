class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void dsu(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);
        if (par_x != par_y) {
            // Union by rank
            if (rank[par_x] > rank[par_y]) {
                parent[par_y] = par_x;
            } else if (rank[par_x] < rank[par_y]) {
                parent[par_x] = par_y;
            } else {
                parent[par_x] = par_y;
                rank[par_y]++;
            }
        }
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Sort indices by their corresponding values
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        // Process sorted indices and connect elements within the limit
        for (int i = 1; i < n; i++) {
            if (nums[indices[i]] - nums[indices[i - 1]] <= limit) {
                dsu(indices[i], indices[i - 1]);
            }
        }

        // Group elements by their connected components
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        // Sort each group and assign sorted values back
        for (auto& group : groups) {
            vector<int>& indices = group.second;
            vector<int> values;
            for (int idx : indices) {
                values.push_back(nums[idx]);
            }

            sort(values.begin(), values.end());
            sort(indices.begin(), indices.end());

            for (int i = 0; i < indices.size(); i++) {
                nums[indices[i]] = values[i];
            }
        }

        return nums;
    }
};
