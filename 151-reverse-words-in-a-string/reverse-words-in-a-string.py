class Solution(object):
    def reverseWords(self, s):
    # Split the string into words
       words=s.split()
    # Reverse the list of words
       reversed_words=words[::-1]
    # Join the reversed words 
       reversed_string=' '.join(reversed_words)

       return(reversed_string)


        