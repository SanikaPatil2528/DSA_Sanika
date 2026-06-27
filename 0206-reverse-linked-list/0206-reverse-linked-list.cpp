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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *first=NULL,*sec=head,*third=head->next;
        while(third){
            sec->next=first;
            first=sec;
            sec=third;
            third=third->next;
        }
        sec->next=first;
        return sec;
    }
};