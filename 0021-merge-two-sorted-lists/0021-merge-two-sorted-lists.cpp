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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr && list2==nullptr) return nullptr;
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;

        ListNode dummy(0);
        ListNode *curr1=list1,*curr2=list2,*curr=&dummy,*head=&dummy;
        while(curr1 && curr2)
        {
            if(curr1->val<=curr2->val)
            {
                curr->next=curr1;
                curr=curr1;
                curr1=curr1->next;
            }
            else
            {
                curr->next=curr2;
                curr=curr2;
                curr2=curr2->next;
            }
        }
        if(curr1) curr->next=curr1;
        else if(curr2) curr->next=curr2;
    
        return head->next;
    }
};