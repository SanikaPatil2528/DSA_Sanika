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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        
        ListNode* second=head;
        ListNode* first=head;
        while((second->next)!=NULL && (second->next->next)!=NULL){
            second=second->next->next;
            first=first->next;
        }
        if(second->next==NULL) return first;
        else if(second->next->next==NULL) return first->next;
        return NULL;
    }
};