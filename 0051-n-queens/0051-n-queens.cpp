class Solution {
public:
    bool noAttack(int row, int col, vector<string>& board, int n){
        int x=row;
        int y=col;

        //horizontally left
        while(y>=0){
            if(board[x][y]=='Q')
                return 0;
            
            y--;

        }

        //upper left diagonal
        y=col;
        while(x>=0 and y>=0){
            if(board[x][y]=='Q')
                return 0;
            x--;
            y--;
        }

        //lower left diagonal
        x=row;
        y=col;

        while(x<n and y>=0){
            if(board[x][y]=='Q')
                return 0;
            x++;
            y--;
        }

        return 1;
    }


    void findPossible(int col, int n, vector<string>& board, 
                    vector<vector<string>>& ans){
                
                if(col==n){
                    ans.push_back(board);
                    return;
                }

                for(int row=0; row<n; row++){
                    if(noAttack(row,col,board,n)){
                        board[row][col]='Q';
                        findPossible(col+1,n,board,ans);
                        board[row][col]='.';
                    }
                }
            }


    vector<vector<string>> solveNQueens(int n) {
        vector<string>board;
        vector<vector<string>>ans;
        string temp= string(n,'.');

        for(int i=0; i<n; i++){
            board.push_back(temp);
        }

        findPossible(0,n,board,ans);
        return ans;
    }
};