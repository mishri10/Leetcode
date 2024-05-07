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

ListNode* rev(ListNode* head){
        
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

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        
        ListNode* new_head=rev(head);
        int carry=0;
        ListNode* temp=new_head;
        
        while(temp){
            int x=temp->val;
            x*=2;
            int rem=(carry+x)%10;
            carry=(carry+x)/10;
            temp->val=rem;
            
           
            if(!temp->next and carry){temp->next=new ListNode(carry);
                                      temp=temp->next;}
             temp=temp->next;
        }
        
        return rev(new_head);
        
    }
};