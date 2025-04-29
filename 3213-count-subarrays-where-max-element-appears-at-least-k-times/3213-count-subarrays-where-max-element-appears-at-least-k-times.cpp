class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int maxElement=0;

        for(auto i: nums){
            maxElement=max(maxElement,i);
        }
        long long ans=0;
        int maxElementCnt=0;
        while(j<n){
            if(nums[j]==maxElement)
                maxElementCnt++;

            while(maxElementCnt>=k){
                ans+=(n-j);
                if(nums[i]==maxElement)
                    maxElementCnt--;
                i++;
            }

            
            j++;
        }
        return ans;


    }
};