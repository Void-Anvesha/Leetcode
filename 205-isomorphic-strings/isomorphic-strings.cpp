class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //Mapped char between s & t
        unordered_map<char,char>smap;
        //Char used in t
        unordered_map<char,int>used;
        for(int i=0;i<s.length();i++)
        {  //s[i] already there in map
            if(smap.count(s[i]))
            { //When we  compare then it points to some other character
                if(smap[s[i]]!=t[i]) return false;
            }
            else{
                //No 2 char can poin to same char
                //a->b & d->b
                if(used.count(t[i])) return false;
                 

                 smap[s[i]]=t[i];
                 used[t[i]]=true;

            }
        }
        return true;
    }
};