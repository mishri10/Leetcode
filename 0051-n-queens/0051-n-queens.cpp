class Solution {
public:
    
    bool safe(int row,int col,vector<string>& board, int n){
        
        int x=row, y=col;
        
        //left side        
        while(col>=0){
            if(board[row][col]=='Q')return 0;
            col--;
        }
        
        //upper diagonal
        
   
        col=y;
        while(row>=0 and col>=0){
            if(board[row][col]=='Q')return 0;
            row--;
            col--;
        }
        
        //lower diagonal
        
        row=x;
        col=y;
        while(row<n and col>=0){
            if(board[row][col]=='Q')return 0;
            row++;
            col--;
        }
        
        return 1;
    }
    
    void place(int col,int n,vector<string>& board, vector<vector<string>>& ans){
        
        //base case
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        
        for(int row=0;row<n;row++){
            
            if(safe(row,col,board,n)){
                board[row][col]='Q';
                place(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
        
        return;
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        for(int i=0;i<n;i++){
            board[i]=string(n,'.');
        }
        vector<vector<string>>ans;
        
        place(0,n,board,ans);
        return ans;
    }
};