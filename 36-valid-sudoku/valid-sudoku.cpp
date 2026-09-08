class Solution {
    bool row_checker(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<int> freq(10, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j]!='.'){
                freq[(board[i][j]-'0')]++;
                if (freq[board[i][j]-'0'] == 2) {
                    return false;
                }
                }
            }
           fill(freq.begin(), freq.end(), 0);
        }
        return true;
    }
    bool column_checker(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<int> freq(10, 0);
       for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[j][i]!='.'){
                freq[(board[j][i]-'0')]++;
                if (freq[board[j][i]-'0'] == 2) {
                    return false;
                }
                }
            }
           fill(freq.begin(), freq.end(), 0);
        }
        return true;
    }
    bool box_checker(vector<vector<char>>& board, int r, int c) {
        int nr = r - r % 3;
        int nc = c - c % 3;
        vector<int> freq(10, 0);
        for (int i = nr; i < nr+3; i++) {
            for (int j = nc; j < nc+3; j++) {
                if(board[i][j]!='.'){
                freq[(board[i][j]-'0')]++;
                if (freq[board[i][j]-'0'] == 2) {
                    return false;
                }
                }
            }
           
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = board.size();

        if (!row_checker(board)) return false;
        if (!column_checker(board)) return false;
        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                if (!box_checker(board,i,j)) return false;
            }
        }
        return true;
    }
};