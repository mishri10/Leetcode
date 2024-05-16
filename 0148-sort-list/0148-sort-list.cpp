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
    ListNode* findMid(ListNode* head){
        ListNode* f=head->next;
        ListNode* s=head;
        
        while(f and f->next){
            s=s->next;
            f=f->next->next;
        }
        
        return s;
    }
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* dummy=new ListNode(1);
        
        ListNode* temp=dummy;
        
        while(h1 and h2){
            if(h1->val<=h2->val){
                temp->next=h1;
                h1=h1->next;
            }
            else if(h2->val<h1->val){
                temp->next=h2;
                h2=h2->next;
            }
            temp=temp->next;
        }
        
        while(h1){
            temp->next=h1;
            h1=h1->next;
            temp=temp->next;
        }
        
        while(h2){
            temp->next=h2;
            h2=h2->next;
            temp=temp->next;
        }
        
        return dummy->next;
        
    }
    
    
    ListNode* mergeSort(ListNode* head){
        if(!head or !head->next)return head;
        
        ListNode* mid=findMid(head);
        
        ListNode* h2=mid->next;
        mid->next=NULL;
        ListNode* h1=head;
        
        h1=mergeSort(h1);
        h2=mergeSort(h2);
        
        return merge(h1,h2);
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};