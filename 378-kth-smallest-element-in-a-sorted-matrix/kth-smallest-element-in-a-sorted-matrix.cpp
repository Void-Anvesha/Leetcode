class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        //Pair : {el,{row,col}}
        priority_queue<
          pair<int,pair<int,int>>,
          vector< pair<int,pair<int,int>>>,
          greater<pair<int,pair<int,int>>>
          >p;

          //push the 1sst el of each row in a Sorted Matrix
          for(int i=0;i<n;i++)
          {
            p.push({matrix[i][0],{i,0}});
          }

        pair<int,pair<int,int>>el;
        int ans=-1;
        int i,j;
        while(k--)
        {
            el=p.top();
            p.pop();
            ans=el.first;
            i=el.second.first;
            j=el.second.second;
            if(j+1<n)
            {
                p.push({matrix[i][j+1],{i,j+1}});
            }

        }
        return ans;
    }
};