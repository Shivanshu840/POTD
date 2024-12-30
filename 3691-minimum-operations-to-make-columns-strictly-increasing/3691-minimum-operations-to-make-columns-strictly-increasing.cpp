class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for(int i = 0;i<row-1;i++){
            for(int j = 0;j<col;j++){

                if(grid[i+1][j]<=grid[i][j]){
                    int diff = abs(grid[i+1][j]-grid[i][j])+1;
                    grid[i+1][j] = grid[i+1][j] + diff;
                    count += diff;

                }
            }
        }

        return count;
        
    }
};