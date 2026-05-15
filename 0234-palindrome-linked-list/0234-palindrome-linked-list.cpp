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
    ListNode* reverseList(ListNode* head){
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *first=head,*second=head->next,*third=second->next;
        first->next=nullptr;
        while(third){
            second->next=first;
            first=second;
            second=third;
            third=third->next;
        }
        second->next=first;
        return second;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        ListNode *slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=reverseList(slow);
        ListNode* head1=head;
        while(head1 && head2){
            if(head1->val!=head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};