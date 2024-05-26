class Solution {
public:
    int helper(int i,int j,int final_x, int final_y, vector<vector<int>>& grid,
               vector<vector<int>>& dp){
        
        if(i<0 or i>final_x or j<0 or j>final_y)return 1e5;        
        if(i==final_x and j==final_y)return grid[final_x][final_y];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int down= grid[i][j]+ helper(i+1,j,final_x,final_y, grid, dp);
        int right= grid[i][j]+helper(i,j+1,final_x,final_y, grid, dp);
        
        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,n-1,m-1,grid,dp);
    }
};