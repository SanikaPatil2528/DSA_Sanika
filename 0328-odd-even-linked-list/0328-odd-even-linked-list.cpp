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
        if(!head || !head->next) return head;
        ListNode *odd=head,*evenHead=head->next,*even=head->next,*oddPrev=NULL;
        while(odd && even){
            if(odd->next==even){
                odd->next=even->next;
                oddPrev=odd;
                odd=odd->next;
            }
            else if(even->next==odd){
                even->next=odd->next;
                even=even->next;
            }
        }
        if(odd) odd->next=evenHead;
        else oddPrev->next=evenHead;
        return head;
    }
};