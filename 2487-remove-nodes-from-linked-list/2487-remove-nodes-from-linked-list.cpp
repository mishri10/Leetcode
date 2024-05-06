/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;}
    
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp=head;
        
        while(temp){
            while(!st.empty() and st.top()->val<temp->val)st.pop();
            
            st.push(temp);
            temp=temp->next;
        }
        
        ListNode* newHead;
        if(!st.empty()){newHead=st.top();st.pop();}
        temp=newHead;
        
        while(!st.empty()){
            temp->next=st.top();
            st.pop();
            temp=temp->next;
            
        }
        temp->next=NULL;
        
        return reverse(newHead);
       
        
        
    }
};