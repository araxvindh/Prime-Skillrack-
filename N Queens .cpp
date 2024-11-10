#include<bits/stdc++.h>

using namespace std;

bool canPlace(int row, int col, vector<bool>& rflag, vector<bool>& cflag, vector<bool>& trbl, vector<bool>& tlbr, int n) {

    if (rflag[row] || cflag[col] || trbl[row + col] || tlbr[n - 1 + (row - col)]) {
        return false;
    }
    return true;
}

void solveNqueen(vector<bool>& rflag, vector<bool>& cflag, vector<bool>& trbl, vector<bool>& tlbr, vector<vector<bool>>& board, int n, vector<vector<string>>& ans, int row) {
    if (row == n) {
        vector<string> res;
        // Fix index from i to r in the loop
        for (int r = 0; r < n; r++) {
            string ss;
            for (int c = 0; c < n; c++) {
                if (board[r][c]) {
                    ss += "Q";
                } else {
                    ss += ".";
                }
            }
            res.push_back(ss);
        }
        ans.push_back(res);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (canPlace(row, col, rflag, cflag, trbl, tlbr, n)) {
            rflag[row] = true;
            cflag[col] = true;
            trbl[row + col] = true;
            tlbr[n - 1 + (row - col)] = true;
            board[row][col] = true;

            solveNqueen(rflag, cflag, trbl, tlbr, board, n, ans, row + 1);

            // Backtrack
            rflag[row] = false;
            cflag[col] = false;
            trbl[row + col] = false;
            tlbr[n - 1 + (row - col)] = false;
            board[row][col] = false;
        }
    }
}

vector<vector<string>> nQueen(int n) {
    vector<bool> rflag(n);
    vector<bool> cflag(n);
    vector<bool> trbl(2 * n - 1);
    vector<bool> tlbr(2 * n - 1);
    vector<vector<bool>> board(n, vector<bool>(n));

    vector<vector<string>> ans;
    solveNqueen(rflag, cflag, trbl, tlbr, board, n, ans, 0);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> solutions = nQueen(n);

    // Display solutions
    for (auto solution : solutions) {
        for (auto row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
