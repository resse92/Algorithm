use super::util::solution::Solution;

// https://leetcode.cn/problems/make-number-of-distinct-characters-equal/description/

impl Solution {
    pub fn is_equal(cnt_word1: Vec<i32>, cnt_word2: Vec<i32>) -> bool {
        let mut cnt_word1 = cnt_word1;
        let mut cnt_word2 = cnt_word2;

        // 尝试交换所有可能的字母，然后判断交换后的cnt_word1的非0元素是否等于cnt_word2的非0元素数目
        for i in 0..26 {
            for j in 0..26 {
                if cnt_word1[i] == 0 || cnt_word2[j] == 0 {
                    continue;
                }
                cnt_word1[i] -= 1;
                cnt_word1[j] += 1;
                cnt_word2[i] += 1;
                cnt_word2[j] -= 1;
                if cnt_word1.iter().filter(|&x| *x != 0).count()
                    == cnt_word2.iter().filter(|&x| *x != 0).count()
                {
                    return true;
                }
                cnt_word1[i] += 1;
                cnt_word1[j] -= 1;
                cnt_word2[i] -= 1;
                cnt_word2[j] += 1;
            }
        }
        false
    }

    pub fn is_it_possible(word1: String, word2: String) -> bool {
        let mut cnt_word1 = vec![0; 26];
        let mut cnt_word2 = vec![0; 26];

        for c in word1.chars() {
            let idx = (c as u8 - 'a' as u8) as usize;
            cnt_word1[idx] += 1;
        }
        for c in word2.chars() {
            let idx = (c as u8 - 'a' as u8) as usize;
            cnt_word2[idx] += 1;
        }

        return Self::is_equal(cnt_word1, cnt_word2);
    }
}
