class Solution {
public:
    bool checkValidString(string s) {
        int lMax = 0, lMin = 0;
        for(char ch: s){
            if(ch == '('){
                lMax++, lMin++;
            }
            else if (ch == ')'){
                lMax--, lMin--;
            }
            else{
                lMax++, lMin--;
            }
            if(lMax < 0)
                return false;
            lMin = max(0, lMin);
        }

        return lMin == 0;
    }
};