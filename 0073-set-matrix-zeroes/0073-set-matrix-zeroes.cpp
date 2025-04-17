class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

       int n=matrix.size();
       int m=matrix[0].size();

       bool Row0=0, Col0=0;  //1,1

       for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0){
                if(i==0)
                    Row0=1;
                if(j==0)
                    Col0=1;
                else{
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
       }

       for(int row=1; row<n; row++){
        if(matrix[row][0]==0){
            for(int col=1; col<m; col++){
                matrix[row][col]=0;
            }
        }
       }

       for(int col=1; col<m; col++){
        if(matrix[0][col]==0){
            for(int row=1; row<n; row++){
                matrix[row][col]=0;
            }
        }
       }

       if(Row0==1){
        for(int col=0; col<m; col++){
            matrix[0][col]=0;
        }
       }

       if(Col0==1){
        for(int row=0; row<n; row++){
            matrix[row][0]=0;
        }
       }

       
    }
};