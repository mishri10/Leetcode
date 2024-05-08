class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>ans(n);
        
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++)
            pq.push({score[i],i});
        
        int cnt=0;
        
        while(!pq.empty()){
           
            int ind=pq.top().second;
            pq.pop();
            cnt++;
            
            if(cnt==1)ans[ind]="Gold Medal";
            else if(cnt==2)ans[ind]="Silver Medal";
            else if(cnt==3)ans[ind]="Bronze Medal";
            
            else ans[ind]=to_string(cnt);
        }
        return ans;
        
        
    }
};