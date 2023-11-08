use super::util::solution::Solution;

// https://leetcode.cn/problems/find-the-duplicate-number/

impl Solution {
    /**
     * 快指针先进入环，慢指针后进入，等相遇时候快指针比慢指针多走了几圈环，设fast-slow=kn,fast=2*slow
     * 设走t步之后进入环
     * fast=2kn,slow=kn       n为环的长度
     * fast在环内位置为2kn-t-(k-1)n=n-t(或者t-n)正数
     * 重置slow之后，当slow在入口时，slow=t
     * fast=n-t+t刚好也在入口
     */
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut slow = 0;
        let mut fast = 0;
        loop {
            slow = nums[slow] as usize;
            fast = nums[nums[fast] as usize] as usize;
            if slow == fast {
                break;
            }
        }

        slow = 0;
        while slow != fast {
            slow = nums[slow] as usize;
            fast = nums[fast] as usize;
        }

        return slow as i32;
    }
}
