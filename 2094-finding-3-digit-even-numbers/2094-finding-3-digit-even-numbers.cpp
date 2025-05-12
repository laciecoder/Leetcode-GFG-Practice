class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans, mp(10);
        for(int digit: digits)
            mp[digit]++;
        
        for(int i = 1; i <= 9; i++){
            for(int j = 0; j < 9; j++){
                for(int k = 0; k <= 8; k += 2){
                    mp[i]--;
                    mp[j]--;
                    mp[k]--;
                    if(mp[i] >= 0 && mp[j] >= 0 && mp[k] >= 0)
                        ans.push_back(i * 100 + j * 10 + k);
                    mp[i]++;
                    mp[j]++;
                    mp[k]++;
                }
            }
        }

        return ans;
    }
};