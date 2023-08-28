use super::util::solution::Solution;

// https://leetcode.cn/problems/insert-interval/

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = vec![];
        let mut intervals = intervals;
        intervals.push(new_interval);
        intervals.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut current = intervals[0].clone();

        for index in 1..intervals.len() {
            let interval = intervals[index].clone();
            if current[1] >= interval[0] {
                current[1] = interval[1].max(current[1]);
            } else {
                result.push(current);
                current = interval;
            }
        }

        result.push(current);

        result
    }
}
