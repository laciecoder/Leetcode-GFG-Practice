class Solution {
public:
    void dfs(vector<int>& arr, vector<bool>& visited, int node){
        visited[node] = true;
        if(arr[node] == 0)
            return;
        int prev = node - arr[node];
        int next = node + arr[node];
        if(prev >= 0 && !visited[prev]){
            dfs(arr, visited, prev);
        }
        if(next < arr.size() && !visited[next]){
            dfs(arr, visited, next);
        }
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n);
        dfs(arr, visited, start);
        for(int i = 0; i < n; i++){
            if(arr[i] == 0 && visited[i])
                return true;
        }
        return false;
    }
};