class Solution {
public:
    int uRow[4]={-1,0,1,0};
    int uCol[4]={0,1,0,-1};
    void dfs(int row,int col,vector<vector<char>>& grid,int n, int m){
        
        grid[row][col]='2';
        
        for(int k=0;k<4;k++){
            int newRow= row+uRow[k];
            int newCol= col+uCol[k];
            
            if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and grid[newRow][newCol]=='1'){
                
                dfs(newRow,newCol,grid,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};