use clap::builder::Str;

use super::util::solution::Solution;

// https://leetcode.cn/problems/find-maximum-number-of-string-pairs/description/?envType=daily-question&envId=2024-01-17

impl Solution {
    pub fn maximum_number_of_string_pairs(words: Vec<String>) -> i32 {
        let mut result: i32 = 0;
        for i in 0..words.len() {
            for j in (i + 1)..words.len() {
                if words[i].len() != words[j].len() {
                    continue;
                }
                let n = words[i].len();
                let mut flag = true;
                for k in 0..n {
                    if words[i].chars().nth(k) == words[j].chars().nth(n - k - 1) {
                        continue;
                    }
                    flag = false;
                    break;
                }
                if flag {
                    result += 1;
                }
            }
        }
        result
    }
    pub fn maximum_number_of_string_pairs2(words: Vec<String>) -> i32 {
        let mut ans: i32 = 0;
        let mut seen = std::collections::HashSet::new();
        for word in words {
            let f = word.chars().nth(0).unwrap() as i32;
            let l = word.chars().nth(1).unwrap() as i32;
            let key = l * 100 + f;
            if seen.contains(&key) {
                ans += 1;
            }
            seen.insert(f * 100 + l);
        }
        ans
    }
}
