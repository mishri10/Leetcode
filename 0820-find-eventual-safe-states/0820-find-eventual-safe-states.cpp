class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int V=graph.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<graph.size();i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);    
            }
                 
        }
    
        
        vector<int>topo;
       
	    vector<int>indegree(V,0);
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        for(auto it :adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)q.push(i);
	    }
	    
	    
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0)q.push(it);
	        }
	    }
        sort(topo.begin(),topo.end());
	    return topo ;
	}
        
        
        
    };