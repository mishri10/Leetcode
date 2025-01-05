class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> diffArr(n,0);
        for(auto it: shifts){
            int startIdx=it[0];
            int endIdx=it[1];
            int direction=it[2];

            if(direction==1){
                diffArr[startIdx]+=1;
                if(endIdx+1<n)
                    diffArr[endIdx+1]-=1;
            }

            else{
                diffArr[startIdx]-=1;
                if(endIdx+1<n)
                    diffArr[endIdx+1]+=1;
            }
            
        }

        int sum=0;
        string ans(n,' ');
        for(int i=0; i<n; i++){
            sum+=diffArr[i]%26;
            if(sum<0)
                sum+=26;
            int diff= (s[i]-'a'+sum)%26;
            ans[i]=diff+'a';

        }

        return ans;
    }
};
// line sweep algorithm