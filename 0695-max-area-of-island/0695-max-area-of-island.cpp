class Solution {
public:
    int bfs(map<pair<int,int>,bool>&visited,int row, int col,vector<vector<int>>& grid){

        queue<pair<int,int>>q;
        visited[{row,col}] = true;
        q.push({row,col});

        int area = 0;

        while(!q.empty()){
            pair<int,int>frontNode = q.front();
            q.pop();
            int x = frontNode.first;
            int y = frontNode.second;

            area++;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

            for(int i=0; i<4; i++){

                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY]==1 && !visited[{newX,newY}]){

                    visited[{newX,newY}] = true;
                    q.push({newX,newY});
                }
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

      map<pair<int,int>,bool>visited;
        int maxi = 0;

        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j<grid[0].size();j++){

                if(!visited[{i,j}] && grid[i][j]==1){

                    int area = bfs(visited,i,j,grid);
                    cout<<area<<" ";
                    maxi = max(area,maxi);
                }
            }
        }

        return maxi;
        
    }
};