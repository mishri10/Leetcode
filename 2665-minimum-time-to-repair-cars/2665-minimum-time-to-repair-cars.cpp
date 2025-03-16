class Solution {
public:
    long long isPossible(vector<int>& ranks, long long mid){
        long long totalCars=0;

        for(auto i: ranks){
            if (mid < i) continue;  
              long long possible = (long long)sqrt((double)mid / i); 
            totalCars+=possible;
        }
        return totalCars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long high=LONG_MAX;

        for(auto i: ranks){
            high=min(high,(long long)i);
        }

        long long low=1;
        long long sq= (long long) cars* cars;
        high*=sq;

        long long ans=0;

        while(low<=high){
            long long mid= low+(high-low)/2;
            if(isPossible(ranks,mid)>=cars){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
//min(ranks[i])--->max(ranks[i])*cars*cars