class Solution {
public:
    int findUnique(int row, int col, int m, int n, vector<vector<int>>& dp){
        if(row<0 or row>=m or col<0 or col>=n)
            return 0;
        if(row==m-1 and col==n-1)
            return 1;

        if(dp[row][col]!=-1)
            return dp[row][col];

        int down= findUnique(row+1,col,m,n,dp);
        int right= findUnique(row,col+1,m,n,dp);

        return dp[row][col]=down+right;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return findUnique(0,0,m,n,dp);
    }
};