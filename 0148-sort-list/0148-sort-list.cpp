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
    
    ListNode* findMid(ListNode* h){
        ListNode* s=h, *f=h->next;
        
        while(f and f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    
    ListNode* merge(ListNode* l, ListNode* r){
        
        ListNode* dummy= new ListNode(1);
        ListNode* temp=dummy;
        
        while(l and r){
            if(l->val<=r->val){
                temp->next=l;
                l=l->next;
               
            }
            else{
                temp->next=r;
                r=r->next;
                
            }
             temp=temp->next;
                
        }
        
        while(l){
            temp->next=l;
            l=l->next;
            temp=temp->next;
        }
        
        while(r){
            temp->next=r;
            r=r->next;
            temp=temp->next;
        }
        
        return dummy->next;
    }
    ListNode* ms(ListNode* head){
        
        if(!head or !head->next)return head;
        ListNode* mid=findMid(head);
        ListNode* nx=mid->next;
        mid->next=NULL;
        
        ListNode* left=head;
        ListNode* right=nx;
        
        left=ms(left);
        right=ms(right);
        
        return merge(left,right);
        
    }
    ListNode* sortList(ListNode* head) {
       
      
       return ms(head);
    }
};