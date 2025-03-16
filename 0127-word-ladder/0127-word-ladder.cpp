class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        if(s.find(endWord)==s.end())
            return 0;

    queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            string intialWord=q.front().first;
            int time= q.front().second;
            q.pop();

            if(intialWord==endWord)
                return time;
            
            for(int i=0; i<intialWord.size(); i++){
                int intialLetter=intialWord[i];
                for(char ch='a'; ch<='z'; ch++){
                    intialWord[i]=ch;
                    if(s.find(intialWord)!=s.end()){
                        q.push({intialWord,time+1});
                        s.erase(intialWord);
                    }
                    intialWord[i]=intialLetter;
                }

            }
        }
        return 0;

        
    }
};
