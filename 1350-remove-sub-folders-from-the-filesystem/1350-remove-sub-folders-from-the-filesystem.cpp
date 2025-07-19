class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        int n=folder.size();
        vector<string>ans;
        ans.push_back(folder[0]);

        for(int i=1;i<n;i++){
            string lastFolder=ans.back();
            string temp= lastFolder+'/';
            if(folder[i].compare(0,temp.size(),temp)!=0)
                ans.push_back(folder[i]);
        }

        return ans;
    }

};
//["/a","/a/b","/c/d","/c/d/e","/c/f"]
//["/a","/a/b","/c/d","/c/d/e","/c/f"]