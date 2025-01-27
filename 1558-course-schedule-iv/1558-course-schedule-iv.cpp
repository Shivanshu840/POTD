class Solution {
public:
    unordered_map<int, list<int>> adjList;

    // Function to preprocess reachability using BFS/DFS
    void preprocessReachability(vector<vector<bool>>& reachable, int numCourses) {
        for (int i = 0; i < numCourses; i++) {
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto nbr : adjList[node]) {
                    if (!reachable[i][nbr]) {
                        reachable[i][nbr] = true;
                        q.push(nbr);
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& query) {
        // Build adjacency list
        for (int i = 0; i < pre.size(); i++) {
            int u = pre[i][0];
            int v = pre[i][1];
            adjList[u].push_back(v);
        }

        // Initialize reachability matrix
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        
        // Preprocess reachability for all nodes
        preprocessReachability(reachable, numCourses);

        // Answer the queries
        vector<bool> res;
        for (int i = 0; i < query.size(); i++) {
            int u = query[i][0];
            int v = query[i][1];
            res.push_back(reachable[u][v]);
        }

        return res;
    }
};
