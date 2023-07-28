from types import prepare_class
from typing import List


# 把一个数组分成k个子集，每个子集的和相等


class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total_sum = sum(nums)
        target_sum = total_sum / k

        if total_sum % k != 0 or max(nums) > target_sum:
            return False

        def backtrack(subset_index, current_sum, memo):
            if subset_index == k:
                return True

            if (subset_index, current_sum) in memo:
                return memo[(subset_index, current_sum)]

            for i in range(len(nums)):
                if not used[i] and current_sum + nums[i] <= target_sum:
                    used[i] = True
                    if current_sum + nums[i] == target_sum:
                        if backtrack(subset_index + 1, 0, memo):
                            return True
                    elif backtrack(subset_index, current_sum + nums[i], memo):
                        return True
                    used[i] = False

            memo[(subset_index, current_sum)] = False
            return False

        used = [False] * len(nums)
        memo = {}
        return backtrack(1, 0, memo)
