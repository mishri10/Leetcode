class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=0;
        
        
        int end=meetings[0][1];
        if(meetings[0][0]!=1)ans+=(meetings[0][0]-1);
        
        
        for(int i=1;i<meetings.size();i++){
            

            if(meetings[i][0]>end){
                ans+=(meetings[i][0]-end-1);
                
            }
            
            end= max(meetings[i][1],end);
          
            
        }
        
        if(end<days)ans+=(days-end);
        return ans;
    }
};