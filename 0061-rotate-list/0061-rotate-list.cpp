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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* prev = nullptr;
        int count = 0;
        ListNode* curr = head;
        while(curr){
            prev = curr;
            count++;
            curr = curr -> next;
        }
        prev -> next = head;
        k %= count;
        int move = count - k;
        curr = head;
        while(move--){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = nullptr;
        return curr;
    }
};