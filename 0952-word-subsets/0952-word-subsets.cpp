class Solution {
public:
    vector<int>getFreq(string& a){
        vector<int>temp(26,0);
        for(auto i: a){
            temp[i-'a']++;
        }
        return temp;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        bool flag=1;
        vector<string>ans;
        vector<int>freqBasic(26,0);

        for (string word : words2) {
            vector<int> freq = getFreq(word);
            for (int j = 0; j < 26; j++) {
                freqBasic[j] = max(freqBasic[j], freq[j]);
            }
        }

        for(auto i: words1){
            vector<int>freq;
            freq=getFreq(i);

            for(int j=0; j<26; j++){
                if(freqBasic[j]>freq[j]){
                    flag=0;
                    break;
                }
            }

            if(flag==1)
                ans.push_back(i);
            flag=1;
        
        }

        

        return ans;


    }
};