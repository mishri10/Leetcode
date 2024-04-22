class Solution {
public:
    void helper(string temp, vector<string>& possible) {
    for (int pl = 0; pl < 4; pl++) {
        int val = temp[pl] - '0'; // Convert char to int
        int up = (val + 1) % 10; // Increment digit
        int down = (val + 9) % 10; // Decrement digit
        string upStr = temp;
        string downStr = temp;
        upStr[pl] = up + '0'; // Convert int to char
        downStr[pl] = down + '0'; // Convert int to char
        possible.push_back(upStr);
        possible.push_back(downStr);
    }
}
    int openLock(vector<string>& deadends, string target) {
        
        unordered_map<string,int>mp;
        
        for(auto i:deadends)
            mp[i]=1;
        
        if(mp.count("0000")>0)return -1;
        mp["0000"]=1;
        
        queue<pair<string,int>>q;
        q.push({"0000",0});
        
        while(!q.empty()){
            
            string lock=q.front().first;
            int step=q.front().second;
            q.pop();
            
            if(lock==target)return step;
            
            vector<string>possible;
            helper(lock,possible);
            
            for(auto it:possible){
                if(mp.count(it)==0){
                    mp[it]=1;
                    q.push({it,step+1});
                }
            }
        }
        
        return -1;
        
    }
};
//cnn base and performace parameter