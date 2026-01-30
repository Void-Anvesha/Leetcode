class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        long long  N = 1LL*n*n;
        long long gridSum = 0;
        long long gridSqSum =0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                gridSum+= grid[i][j];
                gridSqSum+= grid[i][j] * grid[i][j];
            }
        }

    //Expected sum of N nautural no.
     long long sum = (N*(N + 1))/2;
    //Expected Square Sum of N natural No
    long long SqSum = (N*(N+1)*(2*N+1))/6;

    int sqDiff = gridSqSum - SqSum; //a-b
    int sumDiff = gridSum - sum; // a^2 - b^2

    long long sumAB = sqDiff / sumDiff;

    int a = (sumDiff + sumAB)/2; //repeated
    int b = a-sumDiff; //missing

    return {a,b};
    }
};