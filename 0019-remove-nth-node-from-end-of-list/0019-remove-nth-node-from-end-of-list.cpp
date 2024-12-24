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

        if(!head || !head->next) return nullptr;
        ListNode* fast = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }

        ListNode* slow = head;
        ListNode* tail;

        while(fast){
            tail = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if(slow==head){
            head = head->next;
            return head;
        }
       
        tail->next = tail->next->next;
        return head;
        
    }
};