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

    void process(ListNode* curr, ListNode* l, int& rem){
        if(!l)
            return;
        while(l){
            int sum = l -> val + rem;
            curr = curr -> next = new ListNode(sum % 10);
            rem = sum / 10;
            l = l -> next;
        }
        if(rem){
            curr = curr -> next = new ListNode(rem);
            rem = 0;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int rem = 0;
        while(l1 && l2){
            int sum = l1 -> val + l2 -> val + rem;
            curr = curr -> next = new ListNode(sum % 10);
            rem = sum / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        process(curr, l1, rem);
        process(curr, l2, rem);
        if(rem)
            curr = curr -> next = new ListNode(rem);
        curr = dummy ->  next;
        delete dummy;

        return curr;
    }
};