class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();

        for(auto& row:image)
        {
            int left=0;
            int right=n-1;
            while(left<=right)
            {  //Middle element
                if(left==right){
                    row[left]^=1;//Invert middle element if the row is of odd length
                }
                else{
                    int temp=row[left]^1;
                    row[left]=row[right]^1;
                    row[right]=temp;
                }
                ++left;
                --right;
            }
            
        }
        return image;
    }
};