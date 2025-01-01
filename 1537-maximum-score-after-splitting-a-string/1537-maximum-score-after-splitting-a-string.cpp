class Solution {
public:
    int maxScore(string s) {
        int zeroLeft=0;
        int oneLeft=0;
        int ans=INT_MIN;
        int n=s.size();
        // score= zeroLeft+ oneRight
        // score= zeroLeft+ TotalOne-oneLeft
        // score= zeroLeft- oneLeft + TotalOne(constant);
        // so maximize zeroLeft- oneLeft

        for(int i=0; i<n-1; i++){
            if(s[i]=='0')
                zeroLeft++;
            else
                oneLeft++;

            ans=max(ans,zeroLeft-oneLeft);
        }

        if(s[n-1]=='1')
            oneLeft++;

        return ans+oneLeft;
    }
};