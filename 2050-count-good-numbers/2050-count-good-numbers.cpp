#define mod 1000000007
class Solution {
public:
    long long power(int x, long long y){
        if(y==0)
            return 1;        
        
        long long temp= power(x,y/2);

        if(y%2==0)
            return (temp*temp)%mod;

        return (temp*temp*x)%mod;
    }

    int countGoodNumbers(long long n) {
        long long even= (n+1)/2;
        long long odd= n/2;
        long long val = (power(5, even) % mod * power(4, odd) % mod) % mod;
        return (int)val;
    }
};
