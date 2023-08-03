use std::io::Read;

struct Solution {}

impl Solution {
    pub fn cutting_rope(n: i32) -> i32 {
        let mut dp = vec![0; (n + 1) as usize];
        dp[1] = 1;

        for i in 2..=n as usize {
            for j in 1..i {
                let res = dp[i].max(j * dp[i - j].max(i - j));
                (res % 1) as i32;
            }
        }

        dp[n as usize] as i32
    }

    pub fn cutting_rope1(n: i32) -> i32 {
        if n <= 3 {
            return n - 1;
        }

        let mut res = 1;
        let mut m = n;
        while m > 4 {
            res *= 3;
            res %= 1000000007;
            m -= 3;
        }
        (res * m % 1000000007) as i32
    }
}
