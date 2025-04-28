class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        queue<int>q;

        for(auto it: prerequisites){
            int u=it[0];
            int v=it[1];
            indegree[u]++;
            adj[v].push_back(u);
        }
        int node=0;

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
                node++;
                }
        }

        while(!q.empty()){
            int c=q.front();
            q.pop();
            for(auto it:adj[c]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    node++;
                }
            }
        }


        return node==numCourses;
    }
};