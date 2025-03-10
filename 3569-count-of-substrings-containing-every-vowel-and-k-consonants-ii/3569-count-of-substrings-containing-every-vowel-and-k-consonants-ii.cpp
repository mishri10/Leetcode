class Solution {
public:
    bool isConst(char ch){
        if(ch!='a' and ch!='e' and ch!='i' and ch!='o' and ch!='u')
            return 1;
        return 0;
    }

    bool hasVowel(vector<int>& freq){
        if(freq['a'-'a']!=0 and freq['e'-'a']!=0 and freq['i'-'a']!=0 and 
            freq['o'-'a']!=0 and freq['u'-'a']!=0)
            return 1;
        return 0;
    }

    long long atleast(string word, int k){
        vector<int>freq(26,0);
        int n=word.size();
        int c=0;
        long long ans=0;  
        int start=0;

        for(int end=0; end<n; end++){
            if(isConst(word[end]))
                c++;
            freq[word[end]-'a']++;
            while(c>=k and hasVowel(freq)){
                ans+=(n-end);
                if(isConst(word[start]))
                    c--;
                freq[word[start]-'a']--;
                start++;
            }
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return atleast(word,k)-atleast(word,k+1);
    }
};