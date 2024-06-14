class Node{
    public:
    Node* links[2];
    
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    
    void put(int bit, Node* node){
        links[bit]=node;
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
};

class Trie{
    private: Node* root;
    
    public:
    Trie(){
    root= new Node();}
    
    void insert(int num){
        Node* node=root;
        
        for(int i=31;i>=0;i--){
            int bit= (num>>i)& 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
        
    }
    
    int findMaxXor(int num){
        int ans=0;
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit= (num>>i)&1;
            int required=1-bit;
            if(node->containsKey(required)){
                ans= ans | (1<<i);
                node=node->get(required);
            }
            else{
                node=node->get(bit);
            }
        }
        return ans;
    }
    
    
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
               
        int n=queries.size();
        vector<int>ans(n);
        vector<pair<pair<int,int>,int>>q;
        for(int i=0;i<queries.size();i++){
            int x= queries[i][0];
            int limit= queries[i][1];
            int idx= i;
            
            q.push_back({{limit,x},idx});
        }
        sort(q.begin(),q.end());
        sort(nums.begin(),nums.end());
        
        Trie trie;
        
        int iter=0;
        
        for(auto it:q){
            int limit= it.first.first;
            int x=it.first.second;
            int idx= it.second;
            
            while(iter<nums.size() and nums[iter]<=limit){
                trie.insert(nums[iter]);
                iter++;
            }
            
            if(iter==0)ans[idx]=-1;
            else
                ans[idx]=trie.findMaxXor(x);
        }
        
        return ans;
        
    }
};