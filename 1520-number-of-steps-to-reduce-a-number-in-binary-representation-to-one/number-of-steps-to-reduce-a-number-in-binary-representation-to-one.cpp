class Solution {
public:
    //RMB : Right-Most Bit
    //If a number is odd it's RMB is 1
    //If a number is even it's RMB is 0
    //If we want to add 1 to an odd number
    //From R-L find 1st bit which is 0 & make it 1
    void addOne(string & s){
         
         int i = s.length()-1;
         while(i >= 0 && s[i] != '0'){
            s[i] = '0';
            i--;
         }
        
        if(i < 0){
            s = '1' +s;
        }else{
             s[i] = '1';
        }
    }
    int numSteps(string s) {
        int  op = 0;

        while(s.length() > 1){
            int n = s.length();

            //Even {Right shift to pop RMB}
            if(s[n-1] == '0'){
                s.pop_back();
            }

            //Odd {Add 1 }
            else{
                addOne(s);
            }
        op++;
        }
        return op;
    }
};