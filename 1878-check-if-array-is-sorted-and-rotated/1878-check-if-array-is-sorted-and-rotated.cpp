class Solution {
public:
    bool check(vector<int>& arr) {
        int cnt=0;
        int n=arr.size();

        for(int i=1; i<n; i++){
            if(arr[i]<arr[i-1])
                cnt++;
            if(cnt>=2)return 0;
        }
        if(arr[0]<arr[n-1])
            cnt++;

        return cnt<=1;
    }
};