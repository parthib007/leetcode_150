class Solution {
public:
    int cntNeighbour(vector<vector<int>>& board, int row, int col, int m, int n){
        int ans = 0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 && j==0)    continue;
                int nr = row+i, nc = col+j;
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    if(board[nr][nc]==1 || board[nr][nc]==3)
                        ans++;
                }
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        // below are the different states
        // 0->0 use 0 1->1 use 1 0->1 use 2 and 1->0 use 3
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int neighbours = cntNeighbour(board,i,j,m,n);
                // currently live
                if(board[i][j]==1){
                    if(neighbours<2 || neighbours >3){
                        board[i][j] = 3; //becomes dead
                    }
                } else {
                    if(neighbours==3){
                        board[i][j] = 2; //becomes live
                    }
                }
            }
        }
        // decode now
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2)  board[i][j] = 1;
                else if(board[i][j]==3) board[i][j] = 0;
            }
        }
    }
};
