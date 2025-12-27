class Solution {
public:
   int isVowel(char ch)
   {
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return 1;
    else return 0;
   }
    int maxVowels(string s, int k) {
        int max_Vowels=0,curr_Vowels=0;
        for(int i=0;i<s.size();i++)
        {
            // Adding new el in a substring
            curr_Vowels+=isVowel(s[i]);
            if(i>=k)
            {
                //Removing [i-k]th char from substring
                curr_Vowels-=isVowel(s[i-k]);
            }
            max_Vowels=max(curr_Vowels,max_Vowels);
        }
        return max_Vowels;
    }
};