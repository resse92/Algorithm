class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        cache = {}
        result = float("-inf")
        for num in nums:
            if num % 2 != 0:
                continue
            times = cache.get(num, 0) + 1
            cache[num] = times
            cached = cache.get(result, 0)
            if cached > times:
                result = num
            elif cached == times:
                result = min(num, result)

        return result
