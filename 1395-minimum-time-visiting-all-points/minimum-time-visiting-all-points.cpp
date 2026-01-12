class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int dist=0;
        for(int i=0;i<points.size()-1;i++){
            dist+=max(abs(points[i+1][0]-points[i][0]),
            abs(points[i+1][1]-points[i][1]));
        }
        return dist;
    }
};