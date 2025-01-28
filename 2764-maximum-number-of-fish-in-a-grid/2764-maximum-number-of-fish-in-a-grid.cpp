class Solution {
public:

    int bfs(vector<vector<int>>& grid, map<pair<int,int>,bool>&visited,int row,int col){

        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        visited[{row,col}] = true;
        q.push({row,col});
        int ans = 0;


        while(!q.empty()){
            pair<int,int>node = q.front();
            q.pop();

            int x = node.first;
            int y = node.second;


            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
             ans += grid[x][y];

            for(int i = 0; i<4; i++){
                int newx = dx[i] + x;
                int newy  = dy[i] + y;


                if(newx>=0 && newx<n && newy>=0 && newy<m && !visited[{newx,newy}] && grid[newx][newy]>0){

                    visited[{newx,newy}] = true;
                    q.push({newx,newy});
                }
            }
        }

        return ans;

    }
    int findMaxFish(vector<vector<int>>& grid) {


        map<pair<int,int>,bool>visited;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0; i<n; i++){

            for(int j = 0; j<m; j++){

                if(!visited[{i,j}] && grid[i][j]>0){
                    count = max(bfs(grid,visited,i,j),count);
                }
            }
        }

        return count;
        
    }
};