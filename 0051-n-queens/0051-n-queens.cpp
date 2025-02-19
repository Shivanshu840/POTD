class Solution {
public:
    vector<vector<string>> finalAns;
    int N;

    bool isValid(vector<string>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
            if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false;
            if (col + (row - i) < N && board[i][col + (row - i)] == 'Q') return false;
        }
        return true;
    }

    void solve(vector<string>& board, int level) {
        if (level == N) {
            finalAns.push_back(board);
            return;
        }
        
        for (int i = 0; i < N; i++) {
            if (isValid(board, level, i)) {
                board[level][i] = 'Q';
                solve(board, level + 1);
                board[level][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(N, string(N, '.'));
        solve(board, 0);
        return finalAns;
    }
};
