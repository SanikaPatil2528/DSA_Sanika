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
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode *curr1=l1,*curr2=l2;
        int carry=0;
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        while(curr1 && curr2){
            int sumi=curr1->val+curr2->val+carry;
            temp->next=new ListNode(sumi%10);
            temp=temp->next;
            carry=sumi/10;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1){
            int sumi=curr1->val+carry;
            temp->next=new ListNode(sumi%10);
            temp=temp->next;
            curr1=curr1->next;
            carry=sumi/10;
        }
        while(curr2){
            int sumi=curr2->val+carry;
            temp->next=new ListNode(sumi%10);
            carry=sumi/10;
            curr2=curr2->next;
            temp=temp->next;
        }
        if(carry) temp->next=new ListNode(carry);
        return dummy->next;
    }
};