class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1=g.size();
        int n2=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int right=0;
        int left=0;

        while(left<n2 && right<n1)
        {
            if(s[left]>=g[right])
            {
                right++;
            }
            left++;
           
        }
        return right;
    }
};