class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long solve(string& word, int k){
        map<char, int> vowels;
        long long ans = 0;
        int start = 0;
        int consonant = 0;
        int n = word.size();
        for(int i = 0; i < n; i++){
            char ch = word[i];
            if(isVowel(ch)){
                vowels[ch]++;
            }
            else{
                consonant++;
            }
            while(vowels.size() == 5 && consonant >= k){
                ch = word[start];
                ans += n - i;
                start++;
                if(isVowel(ch)){
                    vowels[ch]--;
                    if(vowels[ch] == 0)
                        vowels.erase(ch);
                }
                else{
                    consonant--;
                }
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return solve(word, k) - solve(word, k + 1);
    }
};