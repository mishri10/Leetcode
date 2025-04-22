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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        int carry=0;
        ListNode* newHead= new ListNode();
        ListNode* dummy= newHead;

        while(l1 or l2 or carry){
            sum+=carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
                }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }

            carry= sum/10;
            dummy->next= new ListNode(sum%10);
            dummy=dummy->next;
            sum=0;

        }
        if(carry){
            dummy->next=new ListNode(sum/10);
        }
        return newHead->next;
    }
};