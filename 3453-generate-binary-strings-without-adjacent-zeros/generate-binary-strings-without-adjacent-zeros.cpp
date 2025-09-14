class Solution {
public:
  void findBinaryStrings(int num,string curr,char last,vector<string>&result){
    if(curr.length()==num){
        result.push_back(curr);
        return;
    }
     findBinaryStrings(num,curr+"1",'1',result);
     if(last!='0') findBinaryStrings(num,curr+"0",'0',result);
  }
    vector<string> validStrings(int n) {
        vector<string>result;
        findBinaryStrings(n,"",'1',result);
        return result;
    }
};