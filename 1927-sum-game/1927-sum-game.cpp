class Solution {
public:
    bool sumGame(string num) {
        int lsum = 0, rsum = 0, lq = 0, rq = 0;
        int n = num.size();
        int start = 0, end = n - 1;
        while(start < end){
            if(num[start] == '?'){
                lq++;
            }
            else{
                lsum += (num[start] - '0');
            }
            if(num[end] == '?'){
                rq++;
            }
            else{
                rsum += (num[end] - '0');
            }
            start++, end--;
        }
        if(lq + rq == 0)
            return lsum != rsum;
        if ((lq + rq) & 1)  
            return true;

        int diff = lsum - rsum;
        int qdiff = rq - lq;
        return diff != 9 * (qdiff) / 2;
    }
};