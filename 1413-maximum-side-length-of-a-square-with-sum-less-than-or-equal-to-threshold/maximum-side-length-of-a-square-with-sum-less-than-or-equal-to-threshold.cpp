class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>>prefix(rows , vector<int>(cols ,0));
        //prefix[i][j] = sum of all el in mat from top_left [0][0] to [i][j]
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                //Why are we subtacting prefix[i-1][j-1]
                //Because it's the common section b/w what we are adding
                prefix[i][j] =(j > 0 ? prefix[i][j-1] : 0)
                 + (i > 0 ? prefix[i-1][j] : 0 ) 
                 -((i>0 && j>0) ?  prefix[i-1][j-1]  : 0)
                 + mat[i][j];
            }
        }
        //Lambda function
        auto sumSquare = [&] ( int i , int j , int r2 , int c2){
            int sum = prefix[r2][c2];
            if(i > 0){
                sum -= prefix[i-1][c2];
            }
            if(j > 0){
                sum-= prefix[r2][j-1];
            }
            if(i>0 && j>0){
                sum+= prefix[i-1][j-1];
            }
            return sum;
        };
       //Square maxSide
        int bestSide = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
            //To find the side
            //And through this we find the diagonally opp cell
                for(int k=0; k<min(rows - i , cols -j); k++){
                    int r2 = i+k;
                    int c2 = j+k;

                    int sum = sumSquare(i, j, r2, c2);

                    if(sum <= threshold){
                        bestSide = max(bestSide , k+1);
                    }else{
                        break;
                    }
                }
            }
        }
     return bestSide;
    }
};