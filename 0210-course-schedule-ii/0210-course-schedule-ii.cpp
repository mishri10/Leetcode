class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>ans;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        queue<int>q;

        for(auto i:pre){
            int u=i[0];
            int v=i[1];
            indegree[u]++;
            adj[v].push_back(u);
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
                if(indegree[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }

        if(ans.size()==n)
            return ans;

        return {};
    }
};