class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col) {
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        board[row][col] = 'b'; // Mark as visited
        for (int i = 0; i < 4; i++) {
            int newX = row + dx[i];
            int newY = col + dy[i];

            if (newX >= 0 && newX < board.size() && newY >= 0 &&
                newY < board[0].size() && board[newX][newY] == 'O') {

                dfs(board, newX, newY);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // First and last column
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);          
            if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1); 
        }

        // First and last row
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O') dfs(board, 0, i);         
            if (board[rows - 1][i] == 'O') dfs(board, rows - 1, i); 
        }

     
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'b') {
                    board[i][j] = 'O'; // Restore border-connected regions
                } else {
                    board[i][j] = 'X'; // Flip other regions to 'X'
                }
            }
        }
    }
};
