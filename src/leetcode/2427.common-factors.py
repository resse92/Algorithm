class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        ans = 0
        hi = self.gcd(a, b)
        for i in range(1, hi + 1):
            if a % i == b % i == 0:
                ans += 1
        return ans

    def gcd(self, a: int, b: int) -> int:
        if b == 0:
            return a
        return self.gcd(b, a % b)
