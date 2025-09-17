#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols, diag, antiDiag;

        backtrack(0, n, board, cols, diag, antiDiag, result);
        return result;
    }

private:
    void backtrack(int row, int n, vector<string>& board,
                   unordered_set<int>& cols,
                   unordered_set<int>& diag,
                   unordered_set<int>& antiDiag,
                   vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols.count(col) || diag.count(row - col) || antiDiag.count(row + col)) continue;

            // place queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag.insert(row - col);
            antiDiag.insert(row + col);

            backtrack(row + 1, n, board, cols, diag, antiDiag, result);

            // remove queen (backtrack)
            board[row][col] = '.';
            cols.erase(col);
            diag.erase(row - col);
            antiDiag.erase(row + col);
        }
    }
};

// ---------------- Driver Code ----------------
int main() {
    Solution sol;

    int n1 = 4;
    auto res1 = sol.solveNQueens(n1);
    cout << "Solutions for n=4:\n";
    for (auto &board : res1) {
        for (auto &row : board) cout << row << "\n";
        cout << "\n";
    }

    int n2 = 1;
    auto res2 = sol.solveNQueens(n2);
    cout << "Solutions for n=1:\n";
    for (auto &board : res2) {
        for (auto &row : board) cout << row << "\n";
        cout << "\n";
    }

    return 0;
}
