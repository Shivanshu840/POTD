class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        vector<vector<int>> ans = grid;
        queue<pair<pair<int,int>,int>>q;
        for(int i =0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    pair<int,int>cordi = {i,j};
                    q.push({cordi,0});
                }
            }
        }
        int anstime = 0;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int x = front.first.first;
            int y = front.first.second;
            int time = front.second;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

            for(int i=0;i<4;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx>=0 && newx<ans.size() && newy>=0 && newy<ans[0].size()&& ans[newx][newy]==1){                
                    anstime = max(anstime,time+1);
                    pair<int,int> cordinate = {newx,newy};
                    q.push({cordinate,time+1});
                    ans[newx][newy] = 2;
                }
            }
            
        }
        for(int i =0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                if(ans[i][j]==1){
                    return -1;
                }
            }
        }
        return anstime;
        
    }
};