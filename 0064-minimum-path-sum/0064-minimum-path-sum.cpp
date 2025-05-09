class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, int n, int m, 
                vector<vector<int>>& dp){
        if(i<0 or i>=n or j<0 or j>=m)
            return 1000000;

        if(i==n-1 and j==m-1)
            return grid[i][j];

        if(dp[i][j]!=-1)    
            return dp[i][j];

        int down = grid[i][j]+ helper(i+1,j,grid,n,m,dp);
        int right= grid[i][j]+ helper(i,j+1,grid,n,m,dp);

        return dp[i][j]=min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,grid,n,m,dp);
    }
};