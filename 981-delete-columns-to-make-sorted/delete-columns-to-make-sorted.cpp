class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int n=strs.size();
        //size of each str
        int k=strs[0].size();
       
        int cnt=0;
        //Traversing each char of each word
        for(int i=0; i<k; i++){
            //Trvaersing each word
            for(int j=1; j<n; j++){
                if(strs[j][i] < strs[j-1][i]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;

    }
};