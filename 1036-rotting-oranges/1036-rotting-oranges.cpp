class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        vector<vector<int>>& grid2 = grid;

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < grid.size(); i++) {

            for (int j = 0; j < grid[i].size(); j++) {

                if (grid2[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }
        int anstime = 0;
        while (!q.empty()) {

            auto frontNode = q.front();
            pair<int, int> dir = frontNode.first;
            int time = frontNode.second;
            int x = dir.first;
            int y = dir.second;
            q.pop();

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {

                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < grid2.size() && newY >= 0 &&
                    newY < grid[0].size() && grid2[newX][newY] == 1) {

                    anstime = max(anstime, time + 1);
                    q.push({{newX, newY}, time + 1});
                    grid2[newX][newY] = 2;
                }
            }
        }

        for(int i =0;i<grid2.size();i++){
            for(int j = 0; j<grid2[i].size();j++){

                if(grid2[i][j]==1) return -1;
            }
        }

        return anstime;
    }
};