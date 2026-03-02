class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        //endZeros : No of zeros starting from end till we see 1st 1
        vector<int>endZeros(n);
        for(int i = 0; i < n; i++){
            int j = n-1;
            int cnt = 0;
            while(j >= 0 && grid[i][j] == 0){
                cnt++;
                j--;
            }
            endZeros[i] = cnt;
        }

    int steps = 0;
    for(int i = 0; i < n; i++){
    //How many zeros ith row need
    //Ex : i = 0 , n=3  {need = 2}
    //0th row needs 2->0
        int need  = n- i -1;
        int j = i;
        while( j < n && endZeros[j] < need){
            j++;
        }
    if(j >= n)return -1;
    steps += (j- i);

    //Now start swapping from the Row found with need
    //Till row which needed no of zeros
    while(j > i){
        swap(endZeros[j] , endZeros[j-1]);
        j--;
    }

    }
return steps;

    }
};