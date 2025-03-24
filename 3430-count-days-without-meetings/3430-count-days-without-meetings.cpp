class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int d=0;

        int lastday=0;

        for(auto i: meetings){

            d+=max(0,i[0]-lastday-1);
            lastday=max(lastday,i[1]);
        }
        d+=(days-lastday);
        return d;
    }
};