class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum1=0,sum2=0;
        int ans=INT_MIN;

        for(auto i: nums){
            sum1+=i;
            ans=max(ans,sum1);
            if(sum1<0)
                sum1=0;
        }

        for(auto i: nums){
            sum2+=i;
            ans=max(ans,abs(sum2));
            if(sum2>0)
                sum2=0;
        }
    return ans;
    }
};