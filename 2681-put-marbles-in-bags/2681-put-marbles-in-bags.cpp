class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans=0;
        vector<long long>temp;
        int n=weights.size();

        for(int i=1; i<n; i++){
            temp.push_back(weights[i-1]+weights[i]);
        }
        sort(temp.begin(),temp.end());

        long long maxi=0;
        long long mini=0;
        int len=temp.size();

        for(int i=0; i<k-1; i++){
            mini+=temp[i];
            maxi+=temp[len-i-1];
        }

        return maxi-mini;
    }
};