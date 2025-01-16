class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        int xr=0;

        if(n%2!=0){
            for(auto i:nums2)
                xr^=i;
        }

        if(m%2!=0){
            for(auto i:nums1)
                xr^=i;
        }

    return xr;
    }
};