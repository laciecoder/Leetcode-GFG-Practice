class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& arr, vector<int>& brr) {
        int n = arr.size();
        vector<int> ans(n);

        set<int> a, b;

        vector<int> temp;

        for(int i = 0; i < n; i++){
            a.insert(arr[i]);
            b.insert(brr[i]);
            temp.clear();
            set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(temp));
            ans[i] = temp.size();
        }

        return ans;
    }
};