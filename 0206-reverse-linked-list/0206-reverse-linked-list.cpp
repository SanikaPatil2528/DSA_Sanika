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
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode* first=head,*second=head->next,*third=second->next;
        first->next=nullptr;
        while(third){
            second->next=first;
            first=second;
            second=third;
            third=third->next;
        }
        second->next=first;
        head=second;
        return head;
    }
};