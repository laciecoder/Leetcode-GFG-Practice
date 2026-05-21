class Solution {
public:
    class Trie{
        public:
        vector<Trie*> nums;
        Trie() {
            nums = vector<Trie*>(10);
        }
    };
    void insert(Trie* root, string str){
        for(char ch: str){
            int pos = ch - '0';
            if(!root -> nums[pos]){
                root -> nums[pos] = new Trie();
            }
            root = root -> nums[pos];
        }
    }

    int depth(Trie* root, string str){
        int count = 0;
        for(char ch: str){
            int pos = ch - '0';
            if(!root -> nums[pos])
                return count;
            count++;
            root = root -> nums[pos];            
        }
        return count;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* root = new Trie();
        for(int num: arr2){
            insert(root, to_string(num));
        }
        int ans = 0;
        for(int num: arr1){
            ans = max(ans, depth(root, to_string(num)));
        }
        return ans;
    }
};