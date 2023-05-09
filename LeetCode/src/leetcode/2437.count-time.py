#
# @lc app=leetcode.cn id=2437 lang=python3
#
# [2437] 有效时间的数目
#


# @lc code=start
class Solution:
    def countTime(self, time: str) -> int:
        time = time.split(":")
        hour, minute = time[0], time[1]
        hour_count = 1
        if hour == "??":
            hour_count = 24
        elif hour[0] == "?":
            hour_count = 3 if int(hour[1]) < 4 else 2
        elif hour[1] == "?":
            hour_count = 10 if int(hour[0]) < 2 else 4

        minute_count = 1
        if minute == "??":
            minute_count = 60
        elif minute[0] == "?":
            minute_count = 6
        elif minute[1] == "?":
            minute_count = 10

        return minute_count * hour_count


# @lc code=end
