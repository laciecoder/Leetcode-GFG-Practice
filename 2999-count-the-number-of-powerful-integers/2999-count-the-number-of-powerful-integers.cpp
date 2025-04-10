class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        // digit DP is hard!
        // solution from editorial, kinda understood this
        string st = to_string(start - 1), fi = to_string(finish);
        return calc(fi, s, limit) - calc(st, s, limit);
    }
    long long calc(string x, string s, int limit){
        if(x.length() < s.length())
            return 0;
        if(x.length() == s.length())
            return x >= s ? 1 : 0;
        string suffix = x.substr(x.length() - s.length(), s.length());
        long long cnt = 0;
        int pre = x.length() - s.length();
        for(int i = 0; i < pre; i++){
            if(limit < (x[i] - '0')){
                cnt += (long long)pow(limit + 1, pre - i);
                return cnt;
            }
            cnt += (long long)(x[i] - '0') * (long long)pow(limit + 1, pre - i - 1);
        }
        if(suffix >= s)
            cnt++;
        return cnt;
    }
};