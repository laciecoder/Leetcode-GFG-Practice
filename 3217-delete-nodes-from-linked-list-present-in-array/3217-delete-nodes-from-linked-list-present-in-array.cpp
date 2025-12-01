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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        unordered_set<int> set(nums.begin(), nums.end());
        while (head) {
            ListNode* ptr = head;
            head = head->next;
            ptr->next = nullptr;
            if (set.count(ptr->val) == 0) {
                curr = curr->next = ptr;
            }
        }
        return dummy->next;
    }
};