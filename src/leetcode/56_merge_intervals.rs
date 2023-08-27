use super::util::solution::Solution;

// https://leetcode.cn/problems/merge-intervals/

impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut result = vec![];
        let mut intervals = intervals;
        let mut current = intervals[0].clone();
        intervals.sort_by(|a, b| a[0].cmp(&b[0]));
        for index in 1..intervals.len() {
            let interval = intervals[index].clone();
            if current[1] >= interval[0] {
                current[1] = current[1].max(interval[1]);
            } else {
                result.push(current);
                current = interval;
            }
        }
        result.push(current);
        return result;
    }
}
