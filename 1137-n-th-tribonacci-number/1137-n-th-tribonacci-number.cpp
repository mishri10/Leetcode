class Solution {
public:
    int tribonacci(int n) {
        
        if(n<2)return n;
        if(n==2)return 1;
        int f=0;
        int s=1;
        int t=1;
        int fourth;
        
        for(int i=3;i<=n;i++){
            fourth=f+s+t;
            f=s;
            s=t;
            t=fourth;
        }
            
    
    return fourth;}
};