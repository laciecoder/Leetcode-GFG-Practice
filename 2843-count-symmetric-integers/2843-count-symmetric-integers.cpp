class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; num++) {
            string s = to_string(num);
            int n = s.length() >> 1;
            if (!(s.length() & 1) && accumulate(s.begin(), s.begin() + n, 0l) == accumulate(s.begin() + n, s.end(), 0l)) 
                count++;
        }
        return count;
    }
};