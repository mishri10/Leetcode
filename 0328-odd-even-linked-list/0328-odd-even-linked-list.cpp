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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next or !head->next->next)return head;
        
        ListNode* oddHead=head, *evenHead=head->next;
        ListNode* oddTemp=oddHead, *evenTemp=evenHead;
        
        while(oddTemp and evenTemp){
            if(evenTemp!=NULL and evenTemp->next!=NULL){
                oddTemp->next=evenTemp->next;
                oddTemp=oddTemp->next;
            }
            if(evenTemp->next==NULL){
                evenTemp->next=NULL;
                break;
            }
            if(oddTemp!=NULL){
                evenTemp->next=oddTemp->next;
                evenTemp=evenTemp->next;
            }
        }
        
        oddTemp->next=evenHead;
        return oddHead;
    }
};