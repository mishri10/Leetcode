class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        unordered_map<int,int>mp;
        int sum=0;
        int mod=1e9 +7;
        int cnt=0;

        for(auto i: arr){
            sum+=i;
            if(sum%2!=0){
                cnt++;
                cnt+=mp[0];
                mp[1]++;
                }

            else{
                cnt+=mp[1];
                mp[0]++;
            }

            cnt%=mod;
            
        }
        return cnt;
    }
};