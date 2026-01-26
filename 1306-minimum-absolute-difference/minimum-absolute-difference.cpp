class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin() , arr.end());
        
        int miniDiff = INT_MAX;
        for(int i=1; i<arr.size(); i++){
            int diff = abs(arr[i] - arr[i-1]);
            miniDiff = min(miniDiff , diff);
        }

        int i=0, j =1;
        while(j < n){
            if(abs(arr[j] - arr[i]) == miniDiff){
              ans.push_back({arr[i],arr[j]});
            }
            i++;
            j++;
        }
     return ans;
    }
};