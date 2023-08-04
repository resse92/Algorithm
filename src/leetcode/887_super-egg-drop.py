#
# @lc app=leetcode id=887 lang=python3
#
# [887] Super Egg Drop
#

# @lc code=start
class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        memo = dict()

        def dp(k, n):
            if k == 1:
                return n
            if n == 0:
                return 0

            if (k, n) in memo:
                return memo[(k, n)]

            lo, hi = 1, n
            # keep a gap of 2 x values to manually check later
            while lo + 1 < hi:
                x = (lo + hi) // 2
                t1 = dp(k - 1, x - 1)
                t2 = dp(k, n - x)

                if t1 < t2:
                    lo = x
                elif t1 > t2:
                    hi = x
                else:
                    lo = hi = x

            ans = 1 + min(max(dp(k - 1, x - 1), dp(k, n - x)) for x in (lo, hi))
            memo[(k, n)] = ans
            return ans

        return dp(k, n)


# @lc code=end
