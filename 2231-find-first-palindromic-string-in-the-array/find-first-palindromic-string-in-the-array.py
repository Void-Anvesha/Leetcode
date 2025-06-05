class Solution(object):
    def firstPalindrome(self, words):
        for word in words:
          rev="".join(reversed(word))
          if(rev==word):
            return word
        return ""
        