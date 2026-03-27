class Solution {
public:
    void leftShift(vector<vector<int>>& temp , int row){
        int n = temp[0].size();
        int first = temp[row][0];
        for(int i = 0; i < n-1; i++){
            temp[row][i] = temp[row][i+1];
        }
        temp[row][n-1]=first;
    }

    void rightShift(vector<vector<int>>& temp , int row){
        int n = temp[0].size();
        int last = temp[row][n-1];
        for(int i = n-1; i > 0; i--){
            temp[row][i] = temp[row][i-1];
        }
        temp[row][0] = last;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>temp = mat;
       k = k %n;
       while(k--){
        for(int i = 0; i < m; i++){
            if(i % 2 == 0){
                leftShift(temp , i);
            }else{
                rightShift(temp , i);
            }    
        }
       }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(temp[i][j] != mat[i][j])return false;
        }
    }
return true;
    }
};