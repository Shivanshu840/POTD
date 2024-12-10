class Solution {
public:
    unordered_map<int, list<int>> adjList;
    void topoSort(int n, int &count) {
        unordered_map<int, int> indeg;
        queue<int> q;

        // indegree calculate karlenge fir

        for (auto itr : adjList) {
            for (auto nbr : itr.second) {
                indeg[nbr]++;
            }
        }

        // insert those node whose indeg == 0 insid the queue

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        // ab simple sa bfs lga do

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            count++;

            for (auto itr : adjList[frontNode]) {

                indeg[itr]--;

            // fir check karenge agr indeg of current node ==0 then push it
            // inside the queue
                if (indeg[itr] == 0) {
                    q.push(itr);
                }
            }

        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();

        // first we will construct the adjList;

        for (int i = 0; i < n; i++) {

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[v].push_back(u);
        }

        int count = 0;
        topoSort(numCourses,count);

        if(count == numCourses) return true;

        return false;
    }
};