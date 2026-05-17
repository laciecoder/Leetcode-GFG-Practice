class Solution {
public:
    bool dfs(vector<int>& arr, vector<bool>& visited, int node){
        visited[node] = true;
        if(arr[node] == 0)
            return true;
        int prev = node - arr[node];
        int next = node + arr[node];
        if(prev >= 0 && !visited[prev] && dfs(arr, visited, prev)){
            return true;
        }
        if(next < arr.size() && !visited[next] && dfs(arr, visited, next)){
            return true;
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n);
        return dfs(arr, visited, start);
    }
};