class Solution {
public:
    int ans=0;
    void helper(int ind, vector<string>& words, unordered_map<char,pair<int,int>>& mp,
               int cnt){
        
        if(ind==words.size()){ans=max(ans,cnt);return;}
        
         helper(ind+1,words,mp,cnt);
        
        bool canPick=1;
        int score=0;
        //pick this word
        unordered_map<char,int>temp;
        for(auto it:words[ind]){
            if(mp[it].second>0){
                score+=mp[it].first;
                temp[it]++;
                mp[it].second--;
            }
            else{
                canPick=0;
                break;
            }
        }
       
       if(canPick){
           helper(ind+1,words,mp,cnt+score);
       }
        
    
        for(auto it: temp){
            
            mp[it.first].second+=it.second;
       }
    }
        
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,pair<int,int>>mp; //char,{score,freq}
        
        for(auto it:letters){
            mp[it].second+=1;
            mp[it].first=score[it-'a'];
        }
        int cnt=0;
        
        helper(0,words,mp,cnt);
        return ans;
        
        
    }
};