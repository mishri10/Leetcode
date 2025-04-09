class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int t=0;

        while(!q.empty()){

            string originalWord= q.front().first;
            int t= q.front().second;
            q.pop();

            if(originalWord==endWord)
                return t;

            for(int j=0; j<originalWord.size(); j++){
                int originalChar=originalWord[j];

                for(char ch='a'; ch<='z'; ch++){
                    originalWord[j]=ch;
                    if(s.find(originalWord)!=s.end()){
                        q.push({originalWord,t+1});
                        s.erase(originalWord);
                    }
                    originalWord[j]=originalChar;
                }
            }
        }
        return 0;
        }
    
};