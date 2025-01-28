class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& vis, 
            vector<vector<int>>& grid, int dr[], int dc[], int n, int m){
                vis[row][col]=1;
                int ans=grid[row][col];

                for(int i=0; i<4; i++){
                    int newRow= row+dr[i];
                    int newCol= col+dc[i];

                    if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and
                        !vis[newRow][newCol] and grid[newRow][newCol]!=0){
                            ans+= dfs(newRow,newCol,vis,grid,
                            dr,dc,n,m);
                        }
                }
                return ans;
            }

    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0 and !vis[i][j]){
                    int temp=dfs(i,j,vis,grid,dr,dc,n,m);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};