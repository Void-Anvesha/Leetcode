class Solution {
public:
    int calPoints(vector<string>& operations) {
       vector<int>ans;
       for(string &it:operations)
       {
        if(it=="C") ans.pop_back();

        else if(it=="D") ans.push_back(2*ans.back());

        else if(it=="+")
        {
            int size=ans.size();
            ans.push_back(ans[size-1]+ans[size-2]);
        }

        else{
            //turns string to integer
            ans.push_back(stoi(it));
        }
             
       }
       int sum=0;
       for(int score:ans)
       {
          sum+=score;
       }
       return sum;
    }
};