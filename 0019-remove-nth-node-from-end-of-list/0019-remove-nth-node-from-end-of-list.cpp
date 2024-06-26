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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        while(n--){
            temp=temp->next;
        }
        ListNode* s=head;
        if(!temp)return head->next;
        
        while(temp->next){
            temp=temp->next;
            s=s->next;
        }
        
        
        s->next=s->next->next;
        return head;
    }
};