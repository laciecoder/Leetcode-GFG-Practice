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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if(!head -> next -> next)
            return ans;
        int len = 0;
        vector<int> v;
        ListNode* prev = head, *curr = prev -> next, *next = curr -> next;
        while(next){
            if(curr -> val > next -> val && curr -> val > prev -> val){
                v.push_back(len);
            }
            if(curr -> val < next -> val && curr -> val < prev -> val){
                v.push_back(len);
            }
            prev = curr;
            curr = next;
            next = next -> next;
            len++;
        }
        if(v.size() < 2){
            return ans;
        }
        ans[1] = v.back() - v.front();
        ans[0] = INT_MAX;
        for(int i = 1; i < v.size(); i++){
            ans[0] = min(ans[0], v[i] - v[i - 1]);
        }
        return ans;
    }
};