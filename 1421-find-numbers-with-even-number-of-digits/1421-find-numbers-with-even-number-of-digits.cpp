class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;

        for(auto i: nums){
            if((i>9 and i<100) or (i>999 and i<10000) or (i==100000))
                cnt++;
        }
        return cnt;
    }
};