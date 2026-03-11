class Solution {
public:
    string gcdOfStrings(string a, string b) {
        return a + b == b + a ? a.substr(0, __gcd(a.length(), b.length())) : "";
    }
};