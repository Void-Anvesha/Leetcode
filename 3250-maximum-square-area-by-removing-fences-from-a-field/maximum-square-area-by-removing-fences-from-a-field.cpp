class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) { 
        //Push the starting & end point of fence
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin() , hFences.end());
        sort(vFences.begin() , vFences.end());

        unordered_set<int>widths;
        unordered_set<int>heights;
         int maxSide =0;

        for(int i=0; i<vFences.size(); i++){
            for(int j=i+1; j<vFences.size(); j++){
                int width = vFences[j] - vFences[i];
                widths.insert(width); 
            }
        }


         for(int i=0; i<hFences.size(); i++){
            for(int j=i+1; j<hFences.size(); j++){
                int height = hFences[j] - hFences[i];
                heights.insert(height); 

                //Found a sqaure;
                if(widths.find(height) != widths.end())maxSide = max(maxSide , height);
            }
        }
       if (maxSide == 0) return -1;
       return (1LL * maxSide * maxSide) % 1000000007;

        
    }
};