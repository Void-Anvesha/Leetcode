class Solution {
public:
    void solve(int n ,string& curr ,int& cnt,int& k ,string& res){
        //Base case
        if(curr.length() == n){
            cnt++;
            if(cnt == k){
                res = curr;
            }
            return;
        }
    
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back() == ch)continue;
           //Do
            curr.push_back(ch);
            //Explore other poss
            solve(n , curr ,cnt ,k , res);

            //Undo
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        string res= "";

        int cnt = 0;
         
        solve(n , curr ,cnt ,k ,res);

    return res;
    }
};