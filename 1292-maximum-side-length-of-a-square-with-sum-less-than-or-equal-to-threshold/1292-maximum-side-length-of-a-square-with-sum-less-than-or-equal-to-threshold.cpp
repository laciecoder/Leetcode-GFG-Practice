class Solution {
public:
    void makePrefix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = (i > 0) ? mat[i - 1][j] : 0;
                int left = (j > 0) ? mat[i][j - 1] : 0;
                int diag = (i > 0 && j > 0) ? mat[i - 1][j - 1] : 0;
                mat[i][j] += up + left - diag;
            }
        }
    }

    int findSum(vector<vector<int>>& mat, int r1, int c1, int len) {
        int r2 = r1 + len - 1, c2 = c1 + len - 1;
        int sum = mat[r2][c2];
        if (r1 > 0) sum -= mat[r1 - 1][c2];
        if (c1 > 0) sum -= mat[r2][c1 - 1];
        if (r1 > 0 && c1 > 0) sum += mat[r1 - 1][c1 - 1];
        return sum;
    }

    bool check(vector<vector<int>>& mat, int length, int threshold) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i + length <= m; i++) {
            for (int j = 0; j + length <= n; j++) {
                if (findSum(mat, i, j, length) <= threshold)
                    return true; 
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        makePrefix(mat);

        int m = mat.size(), n = mat[0].size();

        int start = 1, end = min(m, n);
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (check(mat, mid, threshold))
                start = mid + 1;
            else
                end = mid - 1;
        }
        return end;
};
