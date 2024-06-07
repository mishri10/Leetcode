class Solution {
public:
    string getBase(string& word, unordered_set<string>& s){
        for(int i=1;i<=word.size();i++){
            string temp=word.substr(0,i);
            if(s.count(temp)>0)return temp;
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        unordered_set<string>st(dictionary.begin(),dictionary.end());
        
        string ans;
        string word;
        
        while(getline(ss, word, ' ')){
            ans+=getBase(word,st)+" ";
        }
        ans.pop_back();
        return ans;
    }
};