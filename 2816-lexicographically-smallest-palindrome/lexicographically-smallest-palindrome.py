class Solution(object):
    def makeSmallestPalindrome(self, s):
        #Converting string to list to modify it
        s=list(s) 
        left=0
        right=len(s)-1
        while(left<right):
            if(s[left]!=s[right]):
                #Finding min character to swap
               smaller=min(s[left],s[right])
               s[left]=s[right]=smaller
            
            left+=1
            right-=1
        return "".join(s)

        