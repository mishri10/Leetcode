class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>temp;
        for(int i=0; i<n; i++){
            int ans=0;
            for(int j=i-1; j>=0; j--){
                if(boxes[j]=='1')
                    ans+=(i-j);
            }

            for(int k=i+1; k<n; k++){
                if(boxes[k]=='1')
                    ans+=(k-i);
            }

            temp.push_back(ans);
        }
        return temp;
    }
};