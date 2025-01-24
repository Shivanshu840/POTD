class Solution {
public:
    vector<int> safeNode;
    unordered_map<int, list<int>> adjList;
    bool isCycle(int src, unordered_map<int, bool>& visited,
                 unordered_map<int, bool>& dfsvisited) {
        visited[src] = true;
        dfsvisited[src] = true;
        safeNode[src] = 0;

        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
                bool ans = isCycle(nbr, visited, dfsvisited);
                if (ans == true) {
                    return true;
                }
            }
            if (visited[nbr] && dfsvisited[nbr] == true) {
                return true;
            }
        }

        dfsvisited[src] = false;
        safeNode[src] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> res;
        safeNode.resize(graph.size(), 0);

        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {

                adjList[i].push_back(graph[i][j]);
            }
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;

        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                isCycle(i, visited, dfsVisited);
            }
        }

        for (int i = 0; i < safeNode.size(); i++) {
            if (safeNode[i])
                res.push_back(i);
        }

        return res;
    }
};