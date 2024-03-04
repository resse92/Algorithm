use super::util::solution::Solution;

// https://leetcode.cn/problems/accounts-merge/

// 并查集
struct UnionFind {
    parent: Vec<usize>,
    rank: Vec<usize>,
}
impl UnionFind {
    fn new(n: usize) -> Self {
        let mut parent = vec![];
        let mut rank = vec![];
        for i in 0..n {
            parent.push(i);
            rank.push(0);
        }
        UnionFind { parent, rank }
    }
    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] != x {
            self.parent[x] = self.find(self.parent[x]);
        }
        self.parent[x]
    }
    fn union(&mut self, x: usize, y: usize) {
        let root_x = self.find(x);
        let root_y = self.find(y);
        if root_x != root_y {
            if self.rank[root_x] > self.rank[root_y] {
                self.parent[root_y] = root_x;
            } else if self.rank[root_x] < self.rank[root_y] {
                self.parent[root_x] = root_y;
            } else {
                self.parent[root_y] = root_x;
                self.rank[root_x] += 1;
            }
        }
    }
}

impl Solution {
    pub fn accounts_merge(accounts: Vec<Vec<String>>) -> Vec<Vec<String>> {
        let mut ans = vec![];
        // email_to_index 记录email对应的index
        let mut email_to_index = std::collections::HashMap::new();
        // email_to_name 记录email对应的name
        let mut email_to_name = std::collections::HashMap::new();
        let mut emails = vec![];
        // 遍历accounts
        for account in &accounts {
            let name = account[0].clone();
            for email in account[1..].to_vec() {
                if !email_to_index.contains_key(&email) {
                    email_to_index.insert(email.clone(), emails.len());
                    email_to_name.insert(email.clone(), name.clone());
                    emails.push(email);
                }
            }
        }
        // 并查集初始化
        let mut uf = UnionFind::new(emails.len());
        // 遍历accounts
        for account in &accounts {
            let first_index = *email_to_index.get(&account[1]).unwrap();
            for email in account[2..].to_vec() {
                let next_index = *email_to_index.get(&email).unwrap();
                uf.union(first_index, next_index);
            }
        }

        // 合并同一个root的email
        let mut index_to_emails: std::collections::HashMap<usize, Vec<String>> =
            std::collections::HashMap::new();
        for (email, &index) in email_to_index.iter() {
            let root = uf.find(index);
            let emails = index_to_emails.entry(root).or_insert(vec![]);
            emails.push(email.clone());
        }
        // 对emails排序
        for emails in index_to_emails.values_mut() {
            emails.sort();
        }
        // 构造结果
        for (_, emails) in index_to_emails {
            let mut account = vec![];
            account.push(email_to_name.get(&emails[0]).unwrap().clone());
            account.append(&mut emails.clone());
            ans.push(account);
        }

        ans
    }
}
