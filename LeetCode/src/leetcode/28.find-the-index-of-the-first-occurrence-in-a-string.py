#
# @lc app=leetcode id=28 lang=python3
#
# [28] Find the Index of the First Occurrence in a String
#

# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(haystack) < len(needle):
            return -1

        for i in range(len(haystack)):
            tmp = i
            if len(needle) > len(haystack) - i:
                break
            for j in range(len(needle)):
                if haystack[tmp] != needle[j]:
                    break
                tmp += 1
                if j == len(needle) - 1:
                    return i
        return -1


# @lc code=end
