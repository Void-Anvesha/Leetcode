class Solution {
public:
   bool check(vector<vector<int>>& squares , double mid_y , double totalArea){
     double bottomArea = 0.00000;
     for(auto& square : squares){
          double y = square[1];
          double l = square[2];

          double bot_y = y;
          double top_y = y+l;
         //Full square below
          if(mid_y > top_y) bottomArea += l*l;
          //Some part of the square is below
          else if(mid_y > bot_y) bottomArea += (l)*(mid_y - bot_y);
     }
     return (bottomArea >= (totalArea)/2.0);

   }
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX , high = INT_MIN;
        double totalArea = 0.00000;

        for(auto& square : squares){
            double x = square[0];
            double y = square[1];
            double l = square[2];
            totalArea += l*l;
            low = min(low , y);
            high = max(high , y+l);
        }

        double result_y = 0.00000;

        while(high- low > 1e-5){
            double mid_y = low + (high-low)/2;
            result_y = mid_y;
            //Bottom area is greater
            if(check(squares , mid_y , totalArea)) high = mid_y;
            else low = mid_y;
           

        }
        return result_y;
    }

};