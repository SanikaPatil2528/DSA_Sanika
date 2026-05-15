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
private:
    void helper(ListNode*&head,ListNode*&first,ListNode*second){
        if(first==head) first->next=nullptr;
        if(second==nullptr){
            head=first;
            return;
        };
        ListNode*temp=second->next;
        second->next=first;
        helper(head,second,temp);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* first=head,*second=head->next;
        helper(head,first,second);
        return head;
    }
};