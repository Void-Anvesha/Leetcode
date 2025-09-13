class Solution {
public:
bool isPalindrome(string &s,int l ,int r){
    while(l<=r){
        if(s[l++]!=s[r--])return false;
    }
    return true;
}
void palindromePartition(int idx,string &s,vector<vector<string>>&result,vector<string>&ds){
    if(idx==s.size()){
    result.push_back(ds);
    }
    for(int i=idx;i<s.size();i++){
        if(isPalindrome(s,idx,i)){
            ds.push_back(s.substr(idx,i-idx+1));
            palindromePartition(i+1,s,result,ds);
            ds.pop_back();
        }
    }
   }
vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>ds;
        palindromePartition(0,s,result,ds);
        return result;
    }
};