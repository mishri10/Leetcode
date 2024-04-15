class Solution {
public:
     
    bool isValid(int row,int col,char c,vector<vector<char>>& board){
        
        for(int i=0; i<9;i++){
            
            // for row checking
            if(board[row][i]==c)return 0;
            
            //for col checking
            if(board[i][col]==c)return 0;
            
            //for 3X3 box checking
            
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c)return 0;
            
        }
        
        return 1;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    
                    for(char ch='1';ch<='9';ch++){
                        
                        if(isValid(i,j,ch,board)){
                            board[i][j]=ch;
                            
                            if(solve(board))return 1;
                            
                            else board[i][j]='.';
                        }
                       
                        
                    }
                    return 0;
                }
               
            }}
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
              
        solve(board);
        
        
        
    }
};