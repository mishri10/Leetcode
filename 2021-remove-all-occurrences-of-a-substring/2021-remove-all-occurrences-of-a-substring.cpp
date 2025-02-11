class Solution {
public:
    bool isThere(stack<char> st, string& part){
        int m=part.size();
        int temp= m-1;

        while(temp>=0 and st.top()==part[temp]){
            temp--;
            st.pop();
        }

        return temp==-1;
    }
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();

        stack<char>st;

        for(int i=0; i<n; i++){
            st.push(s[i]);
            if(st.size()>=m){
                if(isThere(st,part)){
                    int cnt=m;
                    while(cnt>0){
                        st.pop();
                        cnt--;
                    }
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }

        return ans;  
    }
};