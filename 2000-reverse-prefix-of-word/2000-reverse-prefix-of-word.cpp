class Solution {
public:
    string reverse(int start,int end,string& word){
        string temp;
        for(int i=end;i>=start;i--){
            temp+=word[i];
        }
        return temp;
    }
    string reversePrefix(string word, char ch) {
        int pivot=0;
        
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                pivot=i;
                break;
            }
        }
        
        string ans=reverse(0,pivot,word);
        
        for(int i=pivot+1;i<word.size();i++)ans+=word[i];
        
        return ans;
    }
};