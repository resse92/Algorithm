#![allow(dead_code)]
mod huawei_od;
mod jianzhi_offer;
// mod leetcode;
pub mod leetcode;
mod sort;

use regex;

use clap::Parser;
use plugin::generate_leetcode;

#[derive(Parser, Debug)]
#[command(author="resse", version="0.0.1", about="auto generate file", long_about = None)]
pub struct Cli {
    // #[arg(short, long, default_value = "leetcode")]
    // source: Option<String>,
    url: String,
    #[arg(short, long, default_value = "rust")]
    lang: String,
}

#[tokio::main]
async fn main() {
    let cli = Cli::parse();

    let url = cli.url;
    // 判断url是否是leetcode
    // 判断格式是否包含leetcode.com/problems 或者 leetcode.cn/problems
    let valid_url = regex::Regex::new(r"leetcode\.(com|cn)/problems/")
        .unwrap()
        .is_match(&url);

    if !valid_url {
        println!("url is not valid, must be leetcode problem url");
        return;
    }

    generate_leetcode(url, "rust".to_string(), "src/leetcode".to_string())
        .await
        .unwrap_or_else(|e| panic!("生成leetcode文件失败: {:?}", e));
}
