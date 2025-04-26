class Solution {
public:
    void dfs(int row, int col, int& temp, vector<vector<int>>& grid,int n, int m){
        
        grid[row][col]=0;
        temp++;

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        for(int i=0; i<4; i++){
            int newRow=row+dr[i];
            int newCol=col+dc[i];
            if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and 
            grid[newRow][newCol]==1)
                dfs(newRow,newCol,temp,grid,n,m);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    int temp=0;
                    dfs(i,j,temp,grid,n,m);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};