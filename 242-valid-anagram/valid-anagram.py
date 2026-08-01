class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        
        d1 = {}
        d2 = {}
        for i in range(len(s)):
            d1[s[i]] = d1.get(s[i],0)+1
            d2[t[i]] = d2.get(t[i],0)+1
        
        return d1 == d2



        
        