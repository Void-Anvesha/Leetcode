class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string word="";
        string result="";
        for(char c:s)
        {
           if(c!=' ')
           {
            word+=c;
           }
           else{
           if(!word.empty()){
           reverse(word.begin(),word.end());
           result+=word+" ";
           word="";
           }
           }
        }
        //Handle the last word
        if(!word.empty())
        {
           reverse(word.begin(),word.end());
           result+=word;
        }
        else if (!result.empty()) {
            // Remove trailing space if last word was followed by space
            result.pop_back();
        }
        return result;
    }
};