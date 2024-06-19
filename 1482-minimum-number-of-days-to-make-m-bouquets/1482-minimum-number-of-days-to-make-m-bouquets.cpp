class Solution {
public:
    bool canMakeBouquet(int mid, int m, int k, vector<int>& bloomDay){
        
        int streak=0;
        int totalBouquet=0;
        
        for(auto it:bloomDay){
            if(mid>=it){
                streak++;}
            else{
                if(streak>=k){
                    totalBouquet+=(streak/k);
                }
                streak=0;
            }
        
        }
        
        if(streak>=k)totalBouquet+=(streak/k);
        
        return totalBouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        
        long long n=bloomDay.size();
        long long val= m* 1ll * k* 1ll;
        if(n< val)return -1;
        for(auto it:bloomDay){
            maxi=max(maxi,it);
            mini=min(mini,it);
        }
        
        int start=mini;
        int end=maxi;
        int ans=0;
        while(start<=end){
            int mid= start+(end-start)/2;
            
            if(canMakeBouquet(mid,m,k,bloomDay)){
                ans=mid;
                end=mid-1;
            }
            
            else start=mid+1;
        }
        
        return ans;
    }
};