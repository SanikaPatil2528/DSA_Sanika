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
    ListNode* reverseLL(ListNode *&head){
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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr=head;
        ListNode *prevNode=NULL;
        while(curr){
            ListNode* temp=curr;
            int cnt=1;
            while(cnt<k && temp){
                temp=temp->next;
                cnt++;
            }
            if(!temp) return head;
            ListNode *nextNode=temp->next;
            temp->next=NULL;
            ListNode *reverseHead=reverseLL(curr);
            curr->next=nextNode;
            if(!prevNode) head=reverseHead;
            else prevNode->next=reverseHead;
            prevNode=curr;
            curr=curr->next;
        }
        return head;
    }
};