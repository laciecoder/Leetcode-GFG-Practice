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
    ListNode* reverse(ListNode* root){
        ListNode* prev = nullptr, *curr = root, *next;
        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow = reverse(slow);
        fast = head;
        int ans = 0;
        while(slow){
            ans = max(ans, fast -> val + slow -> val);
            slow = slow -> next;
            fast = fast -> next;
        }
        return ans;
    }
};