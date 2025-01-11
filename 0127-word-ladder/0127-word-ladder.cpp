class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        unordered_set<string>vis;

        if(s.find(endWord)==s.end())
            return 0;

        while(!q.empty()){

            string word=q.front().first;
            int step=q.front().second;
            q.pop();

            if(word==endWord)
                return step;

            int n=word.size();

            for(int i=0; i<n; i++){
                char original= word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end() and vis.find(word)==vis.end()){
                        vis.insert(word);
                        q.push({word,step+1});
                    }
                        
                }
                word[i]=original;
            }
        }

        return 0;
    }
};