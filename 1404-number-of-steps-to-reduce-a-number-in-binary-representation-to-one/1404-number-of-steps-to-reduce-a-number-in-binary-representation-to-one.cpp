class Solution {
public:
    int numSteps(string s) {
        
        int cnt=0;
        
        while(s!="1"){
            if(s.back()=='0'){
                s.pop_back();
                cnt++;
            }
            
            else{
                bool check=0;
                for(int i=s.size()-1;i>=0;i--){
                    if(s[i]=='0'){
                        s[i]='1';
                        check=1;
                        break;
                    }
                    s[i]='0';
                }
                if(!check)s='1'+s;
                cnt++;
            }
        }
        return cnt;
        
    }
};