use std::io::Read;

struct Solution {}

impl Solution {
    pub fn cutting_rope(n: i32) -> i32 {
        let mut dp = vec![0; (n + 1) as usize];
        dp[1] = 1;

        for i in 2..=n as usize {
            for j in 1..i {
                dp[i] = dp[i].max(j * dp[i - j].max(i - j));
            }
        }

        dp[n as usize] as i32
    }
}
