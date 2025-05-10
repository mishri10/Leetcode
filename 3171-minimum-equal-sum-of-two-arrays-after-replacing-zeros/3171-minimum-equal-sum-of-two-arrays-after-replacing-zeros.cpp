class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans=0;

        long long sum1=0;
        long long sum2=0;
        long long zero1=0,zero2=0;

        for(auto i: nums1){
            if(i==0){
                zero1++;
                sum1+=1;
            }
            else
                sum1+=i;
        }

        for(auto i: nums2){
            if(i==0){
                zero2++;
                sum2+=1;
            }
            else
                sum2+=i;
        }

        if(sum1<sum2 and zero1==0)
            return -1;
        if(sum2<sum1 and zero2==0)
            return -1;

        return max(sum1,sum2);
    }
};