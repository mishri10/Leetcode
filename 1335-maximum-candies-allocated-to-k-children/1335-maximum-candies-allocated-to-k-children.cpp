class Solution {
public:
    long long totalDistr(vector<int>& candies, long long& mid){
        long long child=0;
        for(auto i: candies){
            child+=(i/mid);
        }
        return child;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0;
        for(auto i: candies){
            sum+=i;
        }        
        int low=1;
        long long high=sum;
        long long ans=0;

        while(low<=high){
            long long mid= low+(high-low)/2;

            if(totalDistr(candies,mid)>=k){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};