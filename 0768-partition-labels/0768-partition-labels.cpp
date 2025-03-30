class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int start=0;
        unordered_map<char,int>lastplace;
        int n=s.size();

        for(int i=0; i<n; i++){
            lastplace[s[i]]=i;
        }

        int i=0;
        int temp=0;
        int last=0;
        while(i<n){
            last=max(last,lastplace[s[i]]);
            if(i==last){
                temp=i-start+1;
                ans.push_back(temp);
                start=i+1;
            }
            i++;
        }
        return ans;
    }
};