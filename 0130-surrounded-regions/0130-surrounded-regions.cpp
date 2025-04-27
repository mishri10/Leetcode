class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        for(int i=0; i<n; i++){
            if(board[i][0]=='O'){
                vis[i][0]=1;
                q.push({i,0});
            }
               
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
                
        }

        for(int j=0; j<m; j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                vis[0][j]=1;
            }
                
            if(board[n-1][j]=='O'){
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
                
        }

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newRow=row+dr[i];
                int newCol=col+dc[i];
                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and 
                    board[newRow][newCol]=='O' and !vis[newRow][newCol]){
                        q.push({newRow,newCol});
                        vis[newRow][newCol]=1;
                    }
            }
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' and vis[i][j]==0)
                    board[i][j]='X';
            }
        }
    }
};