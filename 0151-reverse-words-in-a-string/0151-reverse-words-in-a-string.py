class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        strList = s.split()
        strList.reverse()
        return " ".join(strList)
        