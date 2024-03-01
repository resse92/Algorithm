use super::util::solution::Solution;

// https://leetcode.cn/problems/string-to-integer-atoi/description/

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let mut ans = 0;
        let mut is_negative = false;
        let mut is_start = false;
        for c in s.chars() {
            if c == ' ' {
                if is_start {
                    break;
                }
                continue;
            }
            if c == '-' {
                if is_start {
                    break;
                }
                is_negative = true;
                is_start = true;
                continue;
            }
            if c == '+' {
                if is_start {
                    break;
                }
                is_start = true;
                continue;
            }

            is_start = true;
            if c.is_digit(10) {
                if ans > i32::MAX / 10 || (ans == i32::MAX / 10 && c.to_digit(10).unwrap() > 7) {
                    return if is_negative { i32::MIN } else { i32::MAX };
                }
                ans = ans * 10 + c.to_digit(10).unwrap() as i32;
            } else {
                break;
            }
        }
        ans * if is_negative { -1 } else { 1 }
    }
}
