pub mod leetcode;
use std::{error::Error, vec};

use leetcode::LeetCode;
use serde_json::Value;

pub async fn generate_leetcode(
    url: String,
    lang: String,
    target_folder: String,
) -> Result<(), Box<dyn Error>> {
    let leetcode = match leetcode::LeetCode::new() {
        Ok(leetcode) => leetcode,
        Err(e) => {
            println!("error: {:?}", e);
            return Ok(());
        }
    };
    let title = leetcode::get_slug_from(&url)
        .unwrap_or_else(|e| panic!("解析题目slug失败: {:?}", e))
        .replace("-", "_");
    let snippets = leetcode
        .get_code_snippets(url.clone())
        .await
        .map_err(|e| format!("获取代码片段失败: {:?}", e))?
        .json::<Value>()
        .await
        .map_err(|e| format!("解析代码片段失败: {:?}", e))?;

    let empty_snippet = vec![];
    let snippets = snippets["data"]["question"]["codeSnippets"]
        .as_array()
        .unwrap_or(&empty_snippet);

    let target_snippet = snippets
        .iter()
        .find(|snippet| {
            let lang_slug = snippet["langSlug"].as_str().unwrap_or("");
            lang_slug == lang
        })
        .ok_or_else(|| format!("未找到语言为{}的代码片段", lang))?;

    let detail = leetcode
        .get_question_detail(url.clone())
        .await
        .unwrap_or_else(|e| panic!("获取题目详情失败: {:?}", e))
        .json::<Value>()
        .await?;

    let id = match detail["data"]["question"]["questionId"].as_str() {
        Some(id) => id,
        None => panic!("获取题目id失败"),
    };
    let file_suffix = match lang.as_str() {
        "rust" => "rs",
        "python3" => "py",
        _ => panic!("不支持的语言"),
    };
    let filename = format!("{}_{}.{}", id, title, file_suffix);
    // 在target_folder下创建文件，写入代码片段，并在文件头部添加题目描述，同时引入use super::util::solution::Solution;
    let code = target_snippet["code"].as_str().unwrap_or("");
    let mut names = vec!["Solution"];
    // 判断代码中存在TreeNode的情况，在content顶部引入use super::util::solution::TreeNode;
    if code.contains("TreeNode") {
        names.push("TreeNode");
    }

    // 判断代码中存在ListNode的情况，在content顶部引入use super::util::solution::ListNode;
    if code.contains("ListNode") {
        names.push("ListNode");
    }
    let show_braces = names.len() > 1;
    let mut content = format!(
        "use super::util::solution::{}{};\n\n",
        names.join(", "),
        if show_braces { ";" } else { "" }
    );
    // content顶部添加url方便跳转
    content = format!("{}\n\n// {}", content, url.clone());

    // 添加code
    content = format!("{} \n\n {}", content, code);

    // 判断filename是否存在，如果存在则不写入
    if std::path::Path::new(format!("{}/{}", target_folder, filename).as_str()).exists() {
        println!("文件{}已存在，跳过", filename);
        return Ok(());
    }

    // 写入target_folder/filename
    std::fs::write(format!("{}/{}", target_folder, filename), content)?;

    // 在src/leetcode/mod.rs中追加内容，格式如下:
    // #[path = "leetcode111.rs"]\npub mod leetcode111;\n
    let mut new_mod_content = format!(
        "#[path = \"{}\"]\npub mod ___{};\n",
        filename,
        filename[0..filename.len() - 3].to_string()
    );
    let mod_rs_path = format!("{}/mod.rs", target_folder);
    // 判断是否存在src/leetcode/mod.rs，如果不存在则创建
    if !std::path::Path::new(mod_rs_path.as_str()).exists() {
        std::fs::write(format!("{}/mod.rs", target_folder), "")?;
    } else {
        let mod_content_str = std::fs::read_to_string(mod_rs_path.clone())?;
        if mod_content_str.contains(new_mod_content.as_str()) {
            println!("文件{}已存在，跳过", filename);
            return Ok(());
        }
        new_mod_content = format!("{}\n{}", mod_content_str, new_mod_content);
        // 写入src/leetcode/mod.rs
        std::fs::write(mod_rs_path.clone(), format!("{}", new_mod_content))?;
    }

    Ok(())
}
