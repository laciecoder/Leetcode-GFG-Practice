class Solution {
public:
    int getWaveCount(string& str){
        int n = str.size();
        int wave = 0;
        for(int i = 1; i < n - 1; i++){
            wave += ((str[i - 1] < str[i] && str[i] > str[i + 1]) || (str[i - 1] > str[i] && str[i] < str[i + 1]));
        }
        return wave;
    }
    int totalWaviness(int num1, int num2) {
        if(num2 <= 100)
            return 0;
        int cnt = 0;

        for(int i = num1; i <= num2; i++){
            string str = to_string(i);
            cnt += getWaveCount(str);
        }


        return cnt;
    }
};