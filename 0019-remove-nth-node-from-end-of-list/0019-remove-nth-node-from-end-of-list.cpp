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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        if(fast->next==nullptr) return NULL;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        ListNode* slow = head;
        ListNode* tail;
        
        while (fast != nullptr) {
            tail=slow;
            slow = slow->next;
            fast = fast->next;
        }

        if(slow==head){
            head=head->next;
            return head;
        }
        ListNode* x = slow;
        tail->next = tail->next->next;
        delete x;
        return head;
    }
};