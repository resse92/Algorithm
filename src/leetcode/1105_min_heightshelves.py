from typing import List


class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        dp = [float("inf") for i in range(n)]
        dp[0] = 0
        for i in range(n):
            height, width = 0, 0
            for j in range(i, -1, -1):
                height = max(height, books[j][1])
                width += books[j][0]
                if width > shelfWidth:
                    break
                dp[i] = min(dp[i], dp[j - 1] + height) if j > 0 else height
        return dp[-1]
