/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return node;
        unordered_map<Node*,Node*>mp; //original,duplicate
        Node* head= new Node(node->val);
        mp[node]=head;

        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* node=q.front();
            q.pop();

            for(auto it: node->neighbors){
                if(mp.find(it)==mp.end()){
                    mp[it]=new Node(it->val);
                    q.push(it);}
            }
        }

        for(auto it: mp){
            Node* originalNode=it.first;
            Node* duplicateNode=it.second;
            for(auto adj: originalNode->neighbors){
                duplicateNode->neighbors.push_back(mp[adj]);
            }
        }
        return head;
    }
};