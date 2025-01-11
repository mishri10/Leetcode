class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>ans;

        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        queue<int>q;

        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        for(int i=0; i<n; i++){
            if(indegree[i]==0)
                q.push(i);
        }


        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto adjNode: adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0)
                    q.push(adjNode);
            }
        }

        if(ans.size()==n)
            return ans;
        return {};
    }
};