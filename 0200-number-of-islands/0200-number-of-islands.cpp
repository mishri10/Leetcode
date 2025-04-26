class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& temp, int n, int m){
       
        temp[row][col]='0';
        
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        for(int i=0; i<4; i++){
            int newRow= row+dr[i];
            int newCol= col+dc[i];

            if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and 
            temp[newRow][newCol]=='1')
                dfs(newRow,newCol,temp,n,m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<char>>temp(grid.begin(),grid.end());
        int cnt=0;
        

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j]=='1'){
                    dfs(i,j,temp,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};