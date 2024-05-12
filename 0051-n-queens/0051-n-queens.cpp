class Solution {
public:
    
bool isSafe(vector<string>& temp, int row,int col,int n){
   
    
    for(int c=col;c>=0;c--){
        if(temp[row][c]=='Q')return 0;
    }
    
    int x=row,y=col;
    while(x>=0 and y>=0){
        if(temp[x][y]=='Q')return 0;
        x--;y--;
    }
    
    x=row,y=col;
    
    while(x<n and y>=0){
        if(temp[x][y]=='Q')return 0;
        x++;
        y--;
    }
    return 1;
}
void helper(int row,int col,int n,vector<string>& temp, vector<vector<string>>& ans){
        
        if(col==n){
            ans.push_back(temp);
            return;
        }
    
    for(int r=row;r<n;r++){
        if(isSafe(temp,r,col,n)){
            temp[r][col]='Q';
            helper(row,col+1,n,temp,ans);
            temp[r][col]='.';
        }
    }
        
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n);
        for(int i=0;i<n;i++){
            temp[i]=string(n,'.');
        }
        helper(0,0,n,temp,ans);
        return ans;
    }
};