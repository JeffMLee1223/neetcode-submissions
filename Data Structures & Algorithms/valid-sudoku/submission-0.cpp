class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            unordered_set<char> seen;
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    continue;
                }
                if (seen.count(board[r][c])) {
                    return false;
                }
                seen.insert(board[r][c]);
            }
        }

        for (int c = 0; c < 9; c++) {
            unordered_set<char> seen;
            for (int r = 0; r < 9; r++) {
                if (board[r][c] == '.') {
                    continue;
                }
                if (seen.count(board[r][c])) {
                    return false;
                }
                seen.insert(board[r][c]);
            }
        }

        for (int boxr = 0; boxr < 9; boxr += 3) {
            for (int boxc = 0; boxc < 9; boxc += 3) {
                unordered_set<char> seen;
                for (int dr = 0; dr < 3; dr++) {
                    for (int dc = 0; dc < 3; dc++) {
                        if (board[boxr + dr][boxc + dc] == '.') {
                            continue;
                        }
                        if (seen.count(board[boxr + dr][boxc + dc])) {
                            return false;
                        }
                        seen.insert(board[boxr + dr][boxc + dc]);
                    }
                }
            }
        }
        return true;
    }
};
