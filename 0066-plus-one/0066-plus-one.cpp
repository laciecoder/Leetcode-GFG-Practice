class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back() += 1;
        if(digits.back() / 10){
            int rem = 0;
            for(int i = digits.size() - 1; i >= 0; i--){
                digits[i] += rem;
                rem = digits[i] / 10;
                digits[i] %= 10;
                if(!rem)
                    break;
            }
            if(rem)
                digits.insert(digits.begin(), rem);
        }
        return digits;
    }
};