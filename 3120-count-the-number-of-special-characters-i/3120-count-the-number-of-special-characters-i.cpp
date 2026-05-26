class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower = 0, upper = 0;
        for(char ch: word){
            if(ch >= 'A' && ch <= 'Z'){
                upper |= (1 << (ch - 'A'));
            }
            else{
                lower |= (1 << (ch - 'a'));
            }
        }
        int cnt = 0;
        int both = lower & upper;
        for(int i = 0; i < 26; i++){
            if(both & (1 << i))
                cnt++;
        }
        return cnt;
    }
};