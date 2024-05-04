class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        
        int i=0;
        int ans=0;
        int j=people.size()-1;
        
        while(i<=j){
            if(i==j){
                ans++;
                break;
            }
            
            else if(people[i]+people[j]<=limit){
                ans++;
                i++;
                j--;
            }
            
            else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};