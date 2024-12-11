class Solution {
public:
    unordered_map<int, list<int>> adjList;

    vector<int> isCycle(int src, map<int, bool>& visited) {
        map<int, int> parent;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode]) {
                if (!visited[nbr]) {
                    parent[nbr] = frontNode;
                    visited[nbr] = true;
                    q.push(nbr);
                } 
                // If nbr is visited and it's not the parent of frontNode, cycle detected
                else if (visited[nbr] && parent[frontNode] != nbr) {
                    return {frontNode, nbr};
                }
            }
        }

        return {};
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Build the graph using adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);

            map<int, bool> visited;

            // graph bnane wakt hee check karlo cycle banega ya nhii
            vector<int> cycleEdge = isCycle(u, visited);
            if (!cycleEdge.empty()) {
                return {u, v};
            }
        }

        return {};
    }
};
