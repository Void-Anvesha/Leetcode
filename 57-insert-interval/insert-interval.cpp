class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>>result;
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            //Left part of overlapping intervals
            result.push_back(intervals[i]);
            i++;
        }

        //Find out the overlapping part
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        //Add Right most non-overlapping part to result
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;

    }
};