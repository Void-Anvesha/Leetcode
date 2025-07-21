class Solution {
public:
    bool isAnagram(string s1, string s2) {
        //Chech whether both the lengths are same 
        if(!(s1.length()==s2.length())) return false;

        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        return s1==s2;
    }
};