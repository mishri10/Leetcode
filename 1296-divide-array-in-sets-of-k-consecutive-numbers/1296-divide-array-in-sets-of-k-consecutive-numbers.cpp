class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        map<int,int>mp;
        
        for(auto it:nums)
            mp[it]++;
        
        while(mp.size()!=0){
            
            int start=mp.begin()->first;
            int end= start+k-1;
            
            for(int i=0;i<k;i++){
                if(mp.find(start+i)==mp.end())return 0;
                mp[start+i]--;
                if(mp[start+i]==0)mp.erase(start+i);
            }
        }
        return 1;
        
    }
};

//T.C: O(NlogN)--> for pushing elements in map + O(N/k)-->outer while loop * O(k*logN)-->inner loop

//overall T.C --> O(NlogN)+ O(NlogN);