class Solution {
public:
    vector<int> findOrder(int numCourse, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>>adj(numCourse);
        vector<int>indegree(numCourse,0);
        for(auto i: prerequisites){
            int a=i[0];
            int b=i[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int>q;
        for(int i=0; i<numCourse; i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        if(ans.size()==numCourse)
            return ans;
        return {};
    }
};