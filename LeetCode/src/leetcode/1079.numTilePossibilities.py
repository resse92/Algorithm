#
# @lc app=leetcode.cn id=1079 lang=python3
#
# [1079] 活字印刷
#


# @lc code=start
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        count = [0] * 26  # Create a count array to store the frequency of each letter
        for tile in tiles:
            count[ord(tile) - ord("A")] += 1

        return self.backtrack(count)

    def backtrack(self, count):
        total = 0
        for i in range(26):
            if count[i] == 0:
                continue
            total += 1  # Add a new possibility
            count[i] -= 1  # Use one tile of the current letter
            total += self.backtrack(count)  # Recursively explore the remaining tiles
            count[i] += 1  # Backtrack: revert the count

        return total


# @lc code=end
