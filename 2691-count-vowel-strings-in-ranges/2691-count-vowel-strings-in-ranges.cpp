class Solution {
public:
    bool isVowel(string& a){
        int n=a.size();

        if((a[0]=='a' or a[0]=='e' or a[0]=='i' or a[0]=='o' or a[0]=='u') and
        (a[n-1]=='a' or a[n-1]=='e' or a[n-1]=='i' or a[n-1]=='o' or a[n-1]=='u'))
            return 1;

        return 0;

    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>prefix(n,0);
        vector<int>ans1;

        if(isVowel(words[0]))
            prefix[0]=1;

        for(int i=1; i<n; i++){
            if(isVowel(words[i]))
                prefix[i]+=1;
            prefix[i]+=prefix[i-1];
        }

        for(auto it: queries){
            int start= it[0];
            int end= it[1];
            int ans=0;

            if(start>=1)
                ans-=prefix[start-1];
            ans+=prefix[end];

            ans1.push_back(ans);
        }
        return ans1;
    }
};
//O(N)+O(M*N) -->T.C
//["aba","bcb","ece","aa","e"]
//[  1,    1  ,  2  , 3  , 4 ]  