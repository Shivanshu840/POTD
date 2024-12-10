class Solution {
public:

void bfs(map<pair<int,int>,bool>& visited,int row, int col,vector<vector<char>>& grid){
        queue<pair<int,int>>q;
        visited[{row,col}] = true;
        q.push({row,col});

        while(!q.empty()){

            auto frontNode = q.front();
            q.pop();

            int x = frontNode.first;
            int y = frontNode.second;
            

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

            for(int i = 0; i < 4; i++){

                int newX = x + dx[i];
                int newY = y + dy[i];

                if((newX>=0 && newX<grid.size()) && newY>=0 && newY < grid[0].size() && !visited[{newX,newY}] && grid[newX][newY]=='1'){

                    visited[{newX,newY}] = true;
                    q.push({newX,newY});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        
        map<pair<int,int>,bool>visited;
        int count = 0;

        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j<grid[0].size();j++){

                if(!visited[{i,j}] && grid[i][j]=='1'){

                    bfs(visited,i,j,grid);
                    count++;
                }
            }
        }

        return count;
    }
};