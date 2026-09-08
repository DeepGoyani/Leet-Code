

class Solution {
    vector<int> queens;

    bool check(int row, int col) {
        for (int pr = 0; pr < row; pr++) {
            int pc = queens[pr];
            if (pc == col || abs(pr - row) == abs(pc - col)) {
                return false;
            }
        }
        return true;
    }

    int rec(int level, int n) {
        if (level == n) {
            return 1;
        }

        int ans = 0;
        for (int ch = 0; ch < n; ch++) {
            if (check(level, ch)) {
                queens[level] = ch;
                ans += rec(level + 1, n);
                queens[level] = -1; 
            }
        }
        return ans;
    }

public:
    int totalNQueens(int n) {
        queens.assign(n, -1);
        return rec(0, n);
    }
};