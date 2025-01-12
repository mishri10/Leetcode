class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2!=0)
            return 0;

        int open=0;
        int close=0;
        int wildCard=0;

        for(int i=0; i<n; i++){
            if(locked[i]=='0')wildCard++;
            else if(s[i]=='(')open++;
            else close++;

            if((close-open) >wildCard)
                return 0;
        }

        open=0;
        close=0;
        wildCard=0;

        for(int i=n-1; i>=0; i--){
            if(locked[i]=='0')wildCard++;
            else if(s[i]=='(')open++;
            else close++;

            if((open-close) >wildCard)
                return 0;
        }
        return 1;
    }
};