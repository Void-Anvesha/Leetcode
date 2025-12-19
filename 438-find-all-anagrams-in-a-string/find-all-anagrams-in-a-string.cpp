class Solution {
public:
   bool allZero(vector<int>& counter){
      for(int& i:counter){
        if(i!=0)return false;
      }
      return true;
   }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<int>counter(26,0);
        for(int i=0; i<p.size(); i++){
            counter[p[i]-'a']++;
        }

        int i=0 , j=0;
        int k=p.size();
        vector<int>res;
        while(j < n){
            counter[s[j]-'a']--;
           
            //Found window
            if(j - i + 1 == k){
                if(allZero(counter)) res.push_back(i);

                //Shrink the window
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};