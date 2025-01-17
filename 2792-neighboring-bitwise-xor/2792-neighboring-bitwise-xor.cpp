class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int a=0;

        for(auto i: derived)
            a^=i;
        return a==0;
    }
};