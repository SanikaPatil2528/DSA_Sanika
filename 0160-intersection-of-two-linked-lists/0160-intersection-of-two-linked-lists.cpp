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
        int l1=0,l2=0;
        ListNode* temp=headA;
        while(temp){
            l1++;
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            l2++;
            temp=temp->next;
        }
        ListNode *temp1=headA,*temp2=headB;
        
        if(l1!=l2){
            int diff=abs(l1-l2);
            if(l1<l2){
                while(diff--)
                    temp2=temp2->next;
            }
            else{
                while(diff--)
                    temp1=temp1->next;
            }
        }
        
        while(temp1 && temp2){
            if(temp1==temp2) return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return nullptr;
    }
};