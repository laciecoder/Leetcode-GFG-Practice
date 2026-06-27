class Solution {
public:
    int maximumLength(vector<int>& nums) {
         unordered_map<long long, int> fmp;
         for(int v: nums)
            fmp[v]++;
        int ans = 0;
        if(fmp[1] % 2 == 0){
            ans = fmp[1] - 1;
        }
        else{
            ans = fmp[1];
        }
        fmp.erase(1);
        for(auto [num, _]: fmp){
            int cnt = 0;
            long long k = num;
            while(fmp.count(k) && fmp[k] > 1){
                cnt += 2;
                k *= k;
            }
            ans = max(ans, cnt + (fmp.count(k) ? 1 : -1));
        }
        return ans;
    }
};