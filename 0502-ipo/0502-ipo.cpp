class Solution {
public:
    int findMaximizedCapital(int k, int intialCapital, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>>capitals;
        
        int n=profits.size();
        
        for(int i=0;i<n;i++){
            capitals.push_back({capital[i],profits[i]});
        }
        
        priority_queue<int>pq;
        sort(capitals.begin(),capitals.end());
        int i=0;
        
        
        while(k--){
            
            while(i<n and capitals[i].first<=intialCapital){
                pq.push(capitals[i].second);
                i++;
            }
            
            if(!pq.empty()){
                intialCapital+=pq.top();
                pq.pop();
            }
            
        }
        
        return intialCapital;
        
    }
};