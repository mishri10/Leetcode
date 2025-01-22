class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();

        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<vector<int>>q;
        int dr[4]={1,0,-1,0};
        int dc[4]={0,1,0,-1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]==1){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int row=q.front()[0];
            int col=q.front()[1];
            int step=q.front()[2];

            q.pop();

            for(int i=0; i<4; i++){
                int newRow= row+dr[i];
                int newCol= col+dc[i];

                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and 
                !vis[newRow][newCol]){
                    ans[newRow][newCol]=step+1;
                    q.push({newRow,newCol,step+1});
                    vis[newRow][newCol]=1;
                }
            }
        }
        return ans;
    }
};