class Solution {
public:
    string smallestNumber(string pattern) 
    {
        int n=pattern.size()+1;
        string ans="";
        for(int i=1;i<=n;i++)
        {
            ans.push_back(i+'0');
        }
        for(int i=0;i<n-1;i++)             // just checking for n-1 times
        {
            for(int j=0;j<n-1;j++)
            {
                if(pattern[j]=='I')
                {
                    if(ans[j]>ans[j+1])
                    {
                        swap(ans[j],ans[j+1]);
                    }
                }
                else
                {
                    if(ans[j]<ans[j+1])
                    {
                        swap(ans[j],ans[j+1]);
                    }
                }
            }
        }
        return ans;
    }
};