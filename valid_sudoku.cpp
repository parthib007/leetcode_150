class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // use set of characters to store
        vector<set<char>> rows(9), cols(9), boxes(9);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char c = board[i][j];
                if(c=='.')  continue;
                int box_idx = (i/3)*3 + (j/3);
                if(rows[i].count(c) || cols[j].count(c) || boxes[box_idx].count(c))
                    return false;
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[box_idx].insert(c);
            }
        }
        return true;
    }
};
