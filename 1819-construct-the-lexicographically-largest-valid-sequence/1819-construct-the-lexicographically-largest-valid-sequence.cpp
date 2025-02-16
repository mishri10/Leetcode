class Solution {
public:
    bool solve(int i, int n, vector<int>& ans, vector<bool>& used){
        //base case
        if(i==ans.size())
            return 1;

        if(ans[i]!=-1)
            return solve(i+1,n,ans,used);
        
        for(int num=n; num>=1; num--){
            if(used[num])
                continue;

            used[num]=1;
            ans[i]=num;
            if(num==1){
                if(solve(i+1,n,ans,used))
                    return 1;
            }

            else{
            int j= i+num;
            if(j<ans.size() and ans[j]==-1){
                ans[j]=num;
                if(solve(i+1,n,ans,used))
                    return 1;
                ans[j]=-1;

            }
            }

            used[num]=0;
            ans[i]=-1;
            
        }
        return 0;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int>ans(2*n-1,-1);
        vector<bool>used(n+1,0);

        solve(0,n,ans,used);
        return ans;
    }
};