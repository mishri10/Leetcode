class Solution {
public:
    int minimumChairs(string s) {
        int ans=0;
        int cnt=0;
        
        for(auto i:s){
            if(i=='E')cnt++;
            else if(i=='L')cnt--;
            ans=max(ans,cnt);
            
        }
        return ans;
    }
};