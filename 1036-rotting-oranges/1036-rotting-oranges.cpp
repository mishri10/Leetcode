class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0;
        queue<pair<int,int>>q;
        int freshOrange=0;

        int n=grid.size();
        int m=grid[0].size();
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }

            else if(grid[i][j]==1)
                freshOrange++;
        }}

        while(!q.empty()){
            int originalFresh=freshOrange;
            int sz= q.size();
            
            for(int i=0; i<sz; i++){
            int row= q.front().first;
            int col= q.front().second;

            q.pop();

            for(int j=0; j<4; j++){
                int newRow= row+ dr[j];
                int newCol= col+ dc[j];

                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and 
                    grid[newRow][newCol]==1){
                        grid[newRow][newCol]=2;
                        q.push({newRow,newCol});
                        freshOrange--;
                    }
            }

            
        }
        if(freshOrange<originalFresh)
                t++;
        }
        if(freshOrange!=0)
            return -1;
        return t;

    }
};