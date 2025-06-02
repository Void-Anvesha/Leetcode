class Solution(object):
    def lengthOfLastWord(self, s):
        cnt = 0
        i = len(s) - 1

        # Skipping the spaces
        while i >= 0 and s[i] == ' ':
            i -= 1

        # Counting the last word
        while i >= 0 and s[i] != ' ':
            cnt += 1
            i -= 1

        return cnt
