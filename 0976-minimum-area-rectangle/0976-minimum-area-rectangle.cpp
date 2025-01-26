class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        int n=points.size();
        int ans=INT_MAX;
             
        set<pair<int,int>>st;
        
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            
            for(auto i:st){
                int x2=i.first;
                int y2=i.second;
                
                if(st.count({x1,y2}) and st.count({x2,y1})){
                    int area=abs(x2-x1)* abs(y2-y1);
                    ans=min(ans,area);
                }}
                
                st.insert({x1,y1});
            }
        
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};