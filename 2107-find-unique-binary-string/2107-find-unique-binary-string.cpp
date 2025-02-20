class Solution {
public:
    bool helper(int ind, unordered_set<string>& st,string& temp){
        if(ind==st.size()){
            if(st.count(temp)==0){
                return 1;
            }
            return 0;
        }

        for(int i=0; i<st.size(); i++){
            for(char ch='0'; ch<='1'; ch++){
                temp.push_back(ch);
                if(helper(ind+1,st,temp))
                    return 1;
                temp.pop_back();
            }
        }
        return 0;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st(nums.begin(),nums.end());

        string temp;
        
        helper(0,st,temp);
        return temp;
    }
};