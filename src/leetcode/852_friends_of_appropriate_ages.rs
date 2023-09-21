use super::util::solution::Solution;

// https://leetcode.cn/problems/friends-of-appropriate-ages/

impl Solution {
    pub fn num_friend_requests(ages: Vec<i32>) -> i32 {
        let mut res = 0;

        let mut age_count = vec![0; 121];
        for age in ages {
            age_count[age as usize] += 1;
        }

        for i in 1..121 {
            let count_i = age_count[i];
            for j in 1..121 {
                let count_j = age_count[j];
                if i as f32 * 0.5 + 7.0 >= j as f32 {
                    continue;
                }
                if i < j {
                    continue;
                }
                if i < 100 && 100 < j {
                    continue;
                }
                res += count_i * count_j;
                if i == j {
                    res -= count_i;
                }
            }
        }
        res
    }
}
