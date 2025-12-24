class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        long long totalApple=0;
        for(int i=0; i<apple.size(); i++){
            totalApple+=apple[i];
        }
        sort(capacity.rbegin(),capacity.rend());
        long long reqdCapacity=0;
        int cntBoxes=0;
        for(int i=0; i<capacity.size(); i++){
            reqdCapacity+=capacity[i];
            cntBoxes++;

              if(reqdCapacity >=totalApple)break;
        }
        return cntBoxes;
    }
};