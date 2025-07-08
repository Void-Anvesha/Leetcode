class Solution {
public:

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    //In nse we will store the index
    vector<int>nse(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
           st.pop();
        }
        if(st.empty())nse[i]=n;
        else nse[i]=st.top();
        st.push(i);
    }
    return nse;

}

vector<int> prevSmallerElement(vector<int>&arr,int n)
{
    vector<int>pse(n);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()) pse[i]=-1;
        else pse[i]=st.top();
        st.push(i);
    }
    return pse;
}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        nse=nextSmallerElement(heights,n);
        pse=prevSmallerElement(heights,n);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
           int width=nse[i]-pse[i]-1;
           maxi=max(maxi,heights[i]*width);
        }
        return maxi;
    }
};