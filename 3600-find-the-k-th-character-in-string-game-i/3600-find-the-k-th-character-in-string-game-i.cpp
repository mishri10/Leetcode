class Solution {
public:
    char kthCharacter(int k) {
        string ans="a";

        while(ans.size()<k){
            string temp;
            for(auto i: ans){
                int num= (i-'a')%26;
                num+=1;
                temp+=(num+'a');
            }
            ans+=temp;
        }

        return ans[k-1];
    }
};
// k=1 //a
// k=2 //ab
// k=3 //abbc
// k=4 //abbcbccd
//1 --> a; 2-->b ; 3-->b; 4-->c ; 5-->b; 6 -->c ; 7-->c ; 8 --> d