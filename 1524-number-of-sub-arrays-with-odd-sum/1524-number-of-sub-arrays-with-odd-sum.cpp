class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int cnt = 0, m = 1e9+7;
        int sum = 0, odd = 0, even = 1;
        for(int num: arr){
            sum += num;
            if(sum & 1){
                cnt += even;
                odd++;
            }
            else{
                cnt += odd;
                even++;
            }
            cnt %= m;
        }
        return cnt;
    }
};