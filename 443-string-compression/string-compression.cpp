class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0;
        //Count continuous char
        for(int i=0;i<chars.size();i++)
        {
            char ch=chars[i];
            int cnt=0;
            while(i<chars.size() && chars[i]==ch)
            {
                cnt++ ,i++;
            }

            if(cnt==1) chars[idx++]=ch;
            else {
                chars[idx++]=ch;
               string str=to_string(cnt);
               for(char dig:str)
               {
                chars[idx++]=dig;
               }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};