class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> set;
        for(int v: arr2){
            while(v){
                set.insert(v);
                v /= 10;
            }
        }
        int ans = 0;

        for(int v: arr1){
            while(v > 0 && set.count(v) == 0){
                v /= 10;
            }
            int cnt = 0;
            while(v > 0){
                cnt++;
                v /= 10;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};