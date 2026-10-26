class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++){
            vector<int> hash(10,0);
            for(int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                int d = board[i][j] - '0';
                if (hash[d] == 1) return false;
                hash[d]++;
            }
        }

        for(int i = 0; i < 9; i++){
            vector<int> hash(10,0);
            for(int j = 0; j < 9; j++){
                if (board[j][i] == '.') continue;
                int d = board[j][i] - '0';
                if (hash[d] == 1) return false;
                hash[d]++;
            }
        }

        for (int k = 0; k < 9; k++) {
            vector<int> hash(10, 0);
            for (int i = (k / 3) * 3; i < (k / 3) * 3 + 3; i++) {
                for (int j = (k % 3) * 3; j < (k % 3) * 3 + 3; j++) {
                    if (board[i][j] == '.') continue;
                    int d = board[i][j] - '0';
                    if (hash[d] == 1) return false;
                    hash[d]++;
                }
            }
        }
        return true;
    }
};
