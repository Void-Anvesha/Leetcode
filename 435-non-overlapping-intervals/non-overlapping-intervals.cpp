class Solution {
public:
//Comparator to sort intervals by ending time
static bool cmp(const vector<int>&a, const vector<int> &b){
    return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=0;
        int lastEndTime=INT_MIN;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=lastEndTime){
                cnt++;
                lastEndTime=intervals[i][1];
            }
        }
        return (intervals.size()-cnt);

        
    }
};