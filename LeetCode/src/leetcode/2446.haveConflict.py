#
# @lc app=leetcode.cn id=2446 lang=python3
#
# [2446] 判断两个事件是否存在冲突
#
from typing import List


# @lc code=start
class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        _event1 = list(map(lambda x: float(".".join(x.split(":"))), event1))
        _event2 = list(map(lambda x: float(".".join(x.split(":"))), event2))
        if event1[0] > event2[0]:
            _event1, _event2 = _event2, _event1
        start = _event1[1]
        end = _event2[0]
        return start >= end


# @lc code=end
