class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        st.push(directions[0]);
        int cnt=0;
        int n=directions.length();
        for(int i=1;i<n;i++){
            char c=directions[i];
            //RL
            if(st.top()=='R' && c=='L'){
                cnt+=2;
                st.pop();
                c='S';
            }
            //SL
            else if(st.top()=='S' && c=='L'){
                cnt+=1;
                c='S';
            }
            //If RRRRRS  { All the collision will be calculated}
            while(!st.empty() && c=='S'  && st.top()=='R'){
                cnt+=1;
                st.pop();

            }
            st.push(c);
        }
        return cnt;

    }
};