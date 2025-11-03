class Solution {
public:
    int find1bits(int num){
      int cnt=0;
      while(num!=0){
        cnt+=num&1;
        num>>=1;
      }
      return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[this](int a,int b){
            int cntA=this->find1bits(a);
            int cntB=this->find1bits(b);
            if(cntA==cntB) 
            //which no is smaller place it before
               return a<b;
            else 
            //Place the number with less number of count
               return cntA<cntB;
        });
        return arr;
    }

};