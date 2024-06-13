struct Node{
    Node* links[2];
    
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int bit, Node* node){
        links[bit]=node;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit= (num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    
    int findMax(int x){
        int maxi=0;
        
        Node* node=root;
        
        for(int i=31;i>=0;i--){
            int num= (x>>i) & 1;
            int required= 1-num;
            if(node->containsKey(required)){
                maxi= maxi|1<<i;
                node=node->get(required);
            }
            else node=node->get(num);
            
        }
        return maxi;
    }
    
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        Trie trie;
        
        for(auto it:nums){
            trie.insert(it);
        }
        
        for(auto it:nums){
            ans=max(ans,trie.findMax(it));
        }
        
        return ans;
    }
};