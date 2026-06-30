/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA) return headB;
        if(!headB) return headA;
        int l1=0,l2=0;
        ListNode *curr=headA;
        while(curr){
            l1++;
            curr=curr->next;
        }
        curr=headB;
        while(curr){
            l2++;
            curr=curr->next;
        }
        ListNode *curr1=headA,*curr2=headB;
        while(l1>l2){
            curr1=curr1->next;
            l1--;
        }
        while(l2>l1){
            curr2=curr2->next;
            l2--;
        }
        while(curr2 && curr1){
            if(curr1==curr2) return curr1;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
    }
};