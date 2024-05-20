class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();
        int digit=0;
        long long k=nums[0];
        long long ans=0;
        
        while(k){
            k/=10;
            digit++;
        }
        
        for(int it=1;it<=digit;it++){
        
        vector<int>temp;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            long long num=nums[i];
            int rem= num%10;
            num/=10;
            nums[i]=num;
            temp.push_back(rem);
            mp[rem]++;
        }
        long long sz=temp.size();    
        long long total = (sz *(sz-1))/2;
        long long same=0;
            
        for(auto it:mp){
            int k=it.second;
            same+=(k *(k-1))/2;
        }
            
        ans+=(total-same);//different
            
        
            
        
       }
        
        
        return ans;
    }
};