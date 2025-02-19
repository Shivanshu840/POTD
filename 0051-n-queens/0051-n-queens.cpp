class Solution {
public:
    vector<int> NQ;
    vector<vector<int>> res;
    int N;

    bool isValid(int row, int col) {
        for (int i = 0; i < row; i++) {
            int pr = i;
            int pc = NQ[i];
            if (pc == col || abs(pc - col) == abs(pr - row)) {
                return false;
            }
        }
        return true;
    }

    void solve(int level) {
        if (level == N) {
            res.push_back(NQ);
            return;
        }

        for (int i = 0; i < N; i++) {  // 0-based indexing
            if (isValid(level, i)) {
                NQ[level] = i;
                solve(level + 1);
                NQ[level] = -1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        NQ.resize(N, -1);
        solve(0);

        vector<vector<string>> finalAns;
        for (auto& itr : res) {
            vector<string> board;
            for (int row = 0; row < n; row++) {
                string str(n, '.');
                str[itr[row]] = 'Q';
                board.push_back(str);
            }
            finalAns.push_back(board);
        }

        return finalAns;
    }
};
