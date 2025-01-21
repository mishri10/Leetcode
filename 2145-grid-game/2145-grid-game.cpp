class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long upperSum=accumulate(grid[0].begin(),grid[0].end(), 0LL);
        long long lowerSum=0;
        long long ans=LONG_MAX;

        for(int col=0; col<grid[0].size(); col++){
            upperSum-=grid[0][col];
            ans=min(ans,max(lowerSum,upperSum));
            lowerSum+=grid[1][col];
        }
        return ans;
    }
};