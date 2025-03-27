/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == nullptr || headB == nullptr) return nullptr;

        ListNode* first = headA;
        ListNode* second = headB;

        

        while(first!= second){

           first = first==nullptr ? headA : first->next;
           second = second==nullptr ? headB : second->next;

        }


        return first;
        
        
    }
};