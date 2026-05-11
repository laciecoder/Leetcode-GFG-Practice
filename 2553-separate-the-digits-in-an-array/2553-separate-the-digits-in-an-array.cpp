class Solution {
public:
    void insertt(int num, vector<int>& ans){
        vector<int> temp;
        while(num){
            temp.push_back(num % 10);
            num /= 10;
        }
        ans.insert(ans.end(), temp.rbegin(), temp.rend());
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num: nums)
            insertt(num, ans);
        return ans;
    }
};