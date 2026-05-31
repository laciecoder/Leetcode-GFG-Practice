class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        priority_queue<int, vector<int>, greater<int>> pq(asteroids.begin(), asteroids.end());
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            if(top > mass)
                return false;
            mass += top;
        }
        return true;
    }
};