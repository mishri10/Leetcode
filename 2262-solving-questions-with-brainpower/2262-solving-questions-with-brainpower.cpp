class Solution {
public:

    long long helper(int ind, vector<vector<int>>& questions, 
    vector<long long>& temp){
        if(ind>=questions.size()){
            return 0;
        }

        if(temp[ind]!=-1)
            return temp[ind];

        long long pick= questions[ind][0]+ helper(ind+questions[ind][1]+1,
                        questions, temp);

        long long noPick= helper(ind+1,questions,temp);

        return temp[ind]=max(pick,noPick);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>temp(n,-1);
        return helper(0,questions,temp);
    }
};