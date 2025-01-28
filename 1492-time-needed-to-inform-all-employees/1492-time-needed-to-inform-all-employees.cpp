class Solution {
public:
    unordered_map<int, list<int>> adjList;
    void dfs(int src, vector<int>& time, unordered_map<int, bool>& visited,
             int& ans, int curr) {

        visited[src] = true;
        ans = max(ans, curr);

        for (auto itr : adjList[src]) {

            if (!visited[itr]) {

                dfs(itr, time, visited, ans, curr + time[src]);
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {

        unordered_map<int, bool> visited;

        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }

        int ans = 0;

        dfs(headID, informTime, visited, ans, 0);

        return ans;
    }
};