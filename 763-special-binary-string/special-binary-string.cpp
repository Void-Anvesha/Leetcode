class Solution {
public:
    string solve(string s){
        vector<string>specials;
        
        int start = 0;
        int sum = 0;

        for(int i = 0; i < s.length(); i++){
            sum += s[i] == '1' ? 1 : -1;
          //special substr found
            if(sum == 0){
               string inner = s.substr(start+1 , i - start -1);
               specials.push_back("1" + solve(inner) + "0");
               start = i+1;
            }
        }
        sort(specials.begin() , specials.end() , greater<string>());
        string res;

        for(string& str : specials){
            res += str;
        }
     return res;

    }
    string makeLargestSpecial(string s) {
        
        return solve(s);
    }
};