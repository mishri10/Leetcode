class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>distinct,temp;
        for(auto i: nums){
            distinct[i]++;
        }
        int unique= distinct.size(); //3
        int n=nums.size(); //5
        int i=0,j=0;
        int ans=0;
        while(j<n){
            temp[nums[j]]++;
            while(temp.size()==unique){
                ans+=(n-j);
                temp[nums[i]]--;
                if(temp[nums[i]]==0)
                    temp.erase(nums[i]);
                i++;
            }
            
            j++;
        }
        return ans;
    }
};