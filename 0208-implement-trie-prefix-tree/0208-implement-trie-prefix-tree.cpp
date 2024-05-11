class Node{
    
    
   Node* links[26];
   bool flag=false;
    
    public:
    
    
    bool containsKey(char t){
        return links[t-'a']!=NULL;
    }
    
    void put(char t, Node* nxt){
        links[t-'a']=nxt;
    }
    
    Node* get(char t){
        return links[t-'a'];
    }
    
    void setEnd(){
        flag=1;}
    
    bool getEnd(){
        return flag;
    }
    
    
    
    
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        
        Node* dummy=root;
        
        for(int i=0; i<word.size();i++){
            if(!dummy->containsKey(word[i])){
                dummy->put(word[i],new Node());
            }
            
            dummy=dummy->get(word[i]);
        }
        
        dummy->setEnd();}
    
    bool search(string word) {
        
        Node* dummy=root;
        
        for(int i=0;i<word.size();i++){
            
            if(!dummy->containsKey(word[i]))return 0;
            
            else{
                dummy=dummy->get(word[i]);
            }
        }
        
        return dummy->getEnd();
    }
    
    bool startsWith(string prefix) {
        
        Node* dummy=root;
        
        for(int i=0;i<prefix.size();i++){
            if(!dummy->containsKey(prefix[i]))return 0;
            else dummy=dummy->get(prefix[i]);
        }
        
        return 1;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */