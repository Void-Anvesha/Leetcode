class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        
        for(int i = 0; i < chars.size(); i++ ){
            int curr_char = chars[i];
            int cnt = 0;
            //Count continuous char
            while(i < chars.size() && curr_char == chars[i]){
                cnt++; i++;
            }

            if(cnt == 1)chars[index++] = curr_char;
            else{
                chars[index++] = curr_char;
                string str = to_string(cnt);
                for(char& digit : str){
                    chars[index++] = digit;
                }

            }
            i--;
        }
        return index;
    }
};