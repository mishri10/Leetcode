class Solution {
public:
    long long maximumHappinessSum(vector<int>& happy, int k) {
        sort(happy.rbegin(),happy.rend());
        
        long long ans=0,it=0;
        
        for(int i=0;i<k;i++){
            if(happy[i]-it>0){
            ans+=happy[i];
            ans-=it;
            it++;}
        }
        return ans;
        
    }
};
