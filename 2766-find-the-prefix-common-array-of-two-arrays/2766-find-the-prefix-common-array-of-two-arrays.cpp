class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<int>ans;
        int cnt=0;
        vector<int>freq(n+1,0);

        for(int i=0; i<n; i++){
            freq[a[i]]+=1;
            freq[b[i]]+=1;

            if(freq[a[i]]%2==0)
                cnt++;
            if(a[i]!=b[i] and freq[b[i]]%2==0)
                cnt++;

            ans.push_back(cnt);
        }
        return ans;
    }
};