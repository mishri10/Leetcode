class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key, int _val){
            key=_key;
            val=_val;
            prev=NULL;
            next=NULL;
        }
    };
    
    int cap;
    unordered_map<int,Node*>mp;
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);
    
    void deleteNode(Node* node){
        Node* nx=node->next;
        Node* prv=node->prev;
        
        prv->next=nx;
        nx->prev=prv;
        //delete(node);
    }
    
    void addNode(Node* node){
        Node* nx=head->next;
        head->next=node;
        node->prev=head;
        nx->prev=node;
        node->next=nx;
        
    }
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end()){
            Node* node= mp[key];
            int res= node->val;
            deleteNode(node);
            addNode(node);
            mp[key]=head->next;
            return res;
        }
        else return -1;
        
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            deleteNode(node);
            delete(node);
            mp.erase(key);
        }
        
        else if(mp.size()==cap){
            Node* temp=tail->prev;
            deleteNode(temp);
            mp.erase(temp->key);
            delete(temp);
        }
        
        Node* newNode= new Node(key,value);
        addNode(newNode);
        mp[key]=newNode;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */