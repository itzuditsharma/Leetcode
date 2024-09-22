class Solution {
public:
    int recur(vector<vector<char>>& board, string word, int i, int j, int currIndex){
        if(i<0 || j < 0|| i >= board.size()|| j >= board[i].size()) return 0;

        char currChar = board[i][j];
        if(currChar != word[currIndex]) return false;
        if(currIndex == word.size() - 1) return true;

        int count = 0;
        board[i][j] = '$';

        count += recur(board, word, i-1, j, currIndex+1);
        count += recur(board, word, i+1, j, currIndex+1);
        count += recur(board, word, i, j-1, currIndex+1);
        count += recur(board, word, i, j+1, currIndex+1);

        board[i][j] = currChar;

        return count;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                count += recur(board, word, i, j, 0);
                if(count == 1) break;
            }
        }
        return count;
    }
};