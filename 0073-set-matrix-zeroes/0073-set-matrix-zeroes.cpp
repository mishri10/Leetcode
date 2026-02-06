class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool setFirstRowZero=0;
        bool setFirstColZero=0;
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0; i<n; i++){
            if(matrix[0][i]==0)
                setFirstRowZero=1;
        }

        for(int row=0; row<m; row++){
            if(matrix[row][0]==0)
                setFirstColZero=1;
        }

        for(int row=1;row<m;row++){
            for(int col=1; col<n; col++){
                if(matrix[row][col]==0){
                    matrix[row][0]=0;
                    matrix[0][col]=0;
                }
            }
        }

        for(int col=1; col<n; col++){
            if(matrix[0][col]==0){
                for(int row=1;row<m; row++){
                    matrix[row][col]=0;
                }
            }
        }

        for(int row=1; row<m; row++){
            if(matrix[row][0]==0){
                for(int col=1;col<n; col++){
                    matrix[row][col]=0;
                }
            }
        }

        if(setFirstRowZero==1){
            for(int col=0; col<n; col++){
                matrix[0][col]=0;
            }
        }

        if(setFirstColZero==1){
            for(int row=0; row<m; row++){
                matrix[row][0]=0;
            }
        }










    }
};


// [[0,1,2,0],
//  [3,4,5,2],
//  [1,3,1,5]]

// T.C: O(m*n)
// S.C: O(m+n)


// T.C: O(n+m) + O(n*m)
// S.C: O(2) ~ constant