class Solution {
public:
    int countEl(int mid, vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i = n - 1;
        int j = 0;
        int cnt = 0;
        
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                cnt += (i + 1);
                j++;
            } else {
                i--;
            }
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        int ans = left;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int temp = countEl(mid, matrix);
            
            if (temp >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};