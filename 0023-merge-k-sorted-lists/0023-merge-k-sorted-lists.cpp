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
class compare{
    public:
        bool operator()(ListNode* l1,ListNode* l2){
            return l1->val>l2->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,compare>pq;
        int k=lists.size();
        for(auto head:lists)
            if(head) pq.push(head);
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=dummy;
        while(!pq.empty()){
            ListNode*temp=pq.top();
            curr->next=temp;
            curr=curr->next;
            pq.pop();
            if(temp && temp->next) pq.push(temp->next);
        }
        return dummy->next;
    }
};