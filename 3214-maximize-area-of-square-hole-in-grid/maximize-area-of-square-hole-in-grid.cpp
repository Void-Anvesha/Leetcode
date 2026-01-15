class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {      
      //Sort the bars to get the longes consecutive bars which can be deleted 
       //To make maximized square
        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());
         //Len of longest consecutive H & V Bars
        int maxConsecutiveHBars = 1;
        int maxConsecutiveVBars = 1;

        //Find the len of longest consecutine horizontal Bars
        int currConsecutiveHBars = 1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i] - hBars[i-1] == 1)currConsecutiveHBars++;
            else currConsecutiveHBars =1;
            maxConsecutiveHBars = max(maxConsecutiveHBars , currConsecutiveHBars);
        }
        
        //Find the len of longest consecutine Vertical Bars
        int currConsecutiveVBars = 1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i] - vBars[i-1] == 1) currConsecutiveVBars++;
            else  currConsecutiveVBars = 1;
            maxConsecutiveVBars = max(maxConsecutiveVBars , currConsecutiveVBars);
        }
        //Squares width & height must be same
        //If not same then we can reduce the larger one & match it with the smaller one
        int side = min(maxConsecutiveVBars , maxConsecutiveHBars) + 1;
        return side*side;
        

    }
};