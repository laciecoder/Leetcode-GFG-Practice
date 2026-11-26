class Solution {
public:
    bool canAliceWin(int n) {
        if(n <= 10)
            return n == 10;
        bool alice = true;
        int start = 10;
        while(n >= start){
            n -= start;
            start--;
            alice = !alice;
        }
        return !alice ? n != start : false;
    }
};