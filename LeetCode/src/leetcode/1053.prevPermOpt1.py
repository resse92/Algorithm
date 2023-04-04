#
# @lc app=leetcode.cn id=1053 lang=python3
#
# [1053] 交换一次的先前排列
#


# @lc code=start
class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        n = len(arr)
        if n < 2:
            return arr

        i = n - 2
        while i >= 0 and arr[i] <= arr[i + 1]:
            i -= 1

        if i == -1:
            return arr

        j = n - 1
        while j >= 0 and arr[j] >= arr[i]:
            j -= 1

        while j > 0 and arr[j] == arr[j - 1]:
            j -= 1

        arr[i], arr[j] = arr[j], arr[i]
        return arr


# @lc code=end
