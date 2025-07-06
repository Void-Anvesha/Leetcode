class Solution { 
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];
       // To find the leftMax of all the el
        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
         // To find the rightMax of all the el
         for(int i=n-2;i>=0;i--)
         {
            rightMax[i]=max(rightMax[i+1],height[i]);
         }
         int ans=0;
         for(int i=0;i<n;i++)
         {
            ans+=min(leftMax[i],rightMax[i])-height[i];
         }
         return ans;

    }
};