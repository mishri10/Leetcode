class Solution {
public:
    //int ans=INT_MAX;
    int minSum(int row,int prevCol, vector<vector<int>>& grid,int n,int m,
               vector<vector<int>>& dp){
        
        if(row==n)return 0;
        if(dp[row][prevCol]!=-1)return dp[row][prevCol];
        
        int sum=0;int ans=INT_MAX;
        for(int col=0;col<m;col++){
            if(col!=prevCol){
                sum=grid[row][col]+minSum(row+1,col,grid,n,m,dp);
                ans=min(ans,sum);
            }
        }
        
        return dp[row][prevCol]=ans;
        
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans1=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        for(int col=0;col<m;col++){
            int temp= minSum(0,m,grid,n,m,dp);
            ans1=min(ans1,temp);
        }
        
        return ans1;
    }
};