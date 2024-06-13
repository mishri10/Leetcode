class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int>freqSeats(101,0);
        vector<int>freqStudents(101,0);
        
        for(int i=0;i<seats.size();i++){
            freqSeats[seats[i]]++;
            freqStudents[students[i]]++;
        }
        
        int i=0,j=0;
        int ans=0;
        
        while(i<101 and j<101){
            
            while(i<101 and freqSeats[i]==0)i++;
            while(j<101 and freqStudents[j]==0)j++;
            
            if(i<101 and j<101){
            ans+=abs(i-j);

            freqSeats[i]--;
            freqStudents[j]--;}
            
            
        }
        return ans;
    }
};