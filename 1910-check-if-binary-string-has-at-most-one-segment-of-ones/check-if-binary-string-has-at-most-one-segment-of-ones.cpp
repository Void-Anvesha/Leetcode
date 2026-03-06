class Solution {
public:
    //continuous segment : 
    bool checkOnesSegment(string s) {
        return (s.find("01") == string::npos);
    }
};