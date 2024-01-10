use super::util::solution::Solution;

// https://leetcode.cn/problems/construct-k-palindrome-strings/

impl Solution {
    pub fn can_construct(s: String, k: i32) -> bool {
        let mut count = vec![0; 26];
        // 计算所有字母出现的次数
        for c in s.chars() {
            count[(c as u8 - b'a') as usize] += 1;
        }
        // 计算出现奇数次的字母个数
        let mut odd = 0;
        for i in 0..26 {
            if count[i] % 2 == 1 {
                odd += 1;
            }
        }
        // 奇数次字母个数 <= k <= 字符串长度
        odd <= k && k <= s.len() as i32
    }
}
