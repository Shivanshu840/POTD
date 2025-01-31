class Solution {
public:
    unordered_map<int, list<int>> adjList;
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void dsu(int x, int y) {
        int parx = find(x);
        int pary = find(y);
        if (parx == pary) return;

        if (rank[parx] > rank[pary]) {
            parent[pary] = parx;
        } else if (rank[pary] > rank[parx]) {
            parent[parx] = pary;
        } else {
            parent[parx] = pary;
            rank[pary] += 1;
        }
    }

    bool isBipartite(int start, unordered_map<int, int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0; // Assign first color

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adjList[node]) {
                if (color.find(neighbor) == color.end()) {
                    color[neighbor] = 1 - color[node]; // Alternate color
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false; // Odd cycle detected
                }
            }
        }
        return true;
    }

    int bfs(int node) {
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(node);
        visited[node] = true;
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();

                for (int neighbor : adjList[cur]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        return level;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        unordered_map<int, int> color;
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            dsu(u, v);
        }

        unordered_map<int, vector<int>> components;
        for (int i = 1; i <= n; i++) {
            components[find(i)].push_back(i);
        }

        for (auto& comp : components) {
            int root = comp.second[0];

            if (!isBipartite(root, color)) {
                return -1; // Odd-length cycle found
            }

            int maxDepth = 0;
            for (int node : comp.second) {
                maxDepth = max(maxDepth, bfs(node));
            }
            ans += maxDepth;
        }

        return ans;
    }
};
