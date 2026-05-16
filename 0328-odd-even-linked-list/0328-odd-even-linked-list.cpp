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
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* odd=head, *even=head->next, *evenHead=head->next, *oddPrev=nullptr;
        while(odd && even){
            if(odd->next==even){
                odd->next=even->next;
                if(odd->next==nullptr) oddPrev=odd;
                odd=odd->next;
            }
            else if(even->next==odd){
                even->next=odd->next;
                even=even->next;
            }
        }
        if(oddPrev!=nullptr) odd=oddPrev;
        odd->next=evenHead;
        return head;
    }
};