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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int l=0;
        ListNode *curr=head;
        while(curr){
            l++;
            curr=curr->next;
        }
        k=k%l;
        ListNode *first=head,*sec=head;
        while(k--) sec=sec->next;
        while(sec && sec->next){
            sec=sec->next;
            first=first->next;
        }
        sec->next=head;
        ListNode* newHead=first->next;
        first->next=NULL;
        return newHead;
    }
};