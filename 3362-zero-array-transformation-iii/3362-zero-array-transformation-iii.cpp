class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), qn = queries.size();
        sort(queries.begin(), queries.end());
        priority_queue<int> pq;
        int curr = 0, j = 0;
        vector<int> end(n + 1, 0);
        for(int i = 0; i < n; i++){
            curr -= end[i];
            while(j < qn && queries[j][0] <= i){
                pq.push(queries[j][1]);
                j++;
            }
            while(curr < nums[i]){
                if(pq.empty() || pq.top() < i){
                    return -1;
                }
                end[pq.top() + 1]++;
                pq.pop();
                curr++;
            }
        }
        return pq.size();
    }
};