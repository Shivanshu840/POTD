class Solution {
public:
    void solve(vector<vector<char>>& grid,map<pair<int,int>,bool> & visited,int row, int col){
        queue<pair<int,int>>q;
        visited[{row,col}] = true;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){

            pair<int,int>p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

            for(int i = 0; i<4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx>=0 && newx<n && newy>=0 && newy<m && !visited[{newx,newy}]&& grid[newx][newy] == '1'){
                    q.push({newx,newy});
                    visited[{newx,newy}] = true;
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {

       map<pair<int,int>,bool>visited;
       int count = 0;


       for(int i = 0; i<grid.size();i++){
        for(int j = 0; j<grid[i].size();j++){

            if(!visited[{i,j}] && grid[i][j] == '1'){
                solve(grid,visited,i,j);
                count++;
            }
        }
       }

       return count;
        
    }
};