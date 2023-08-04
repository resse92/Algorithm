use self::req::{Json, Mode, Req};

use reqwest::{
    header::{HeaderMap, HeaderName, HeaderValue},
    Client, ClientBuilder, Response,
};
use std::{collections::HashMap, str::FromStr, time::Duration};

#[derive(Debug)]
pub enum Error {
    MatchError,
    DownloadError(String),
    NetworkError(String),
    ParseError(String),
    CookieError,
}

impl From<reqwest::Error> for Error {
    fn from(e: reqwest::Error) -> Self {
        Error::NetworkError(e.to_string())
    }
}

/// LeetCode API set
#[derive(Clone)]
pub struct LeetCode {
    client: Client,
    default_headers: HeaderMap,
}

impl LeetCode {
    /// Parse reqwest headers
    fn headers(mut headers: HeaderMap, ts: Vec<(&str, &str)>) -> Result<HeaderMap, Error> {
        for (k, v) in ts.into_iter() {
            let name = HeaderName::from_str(k);
            let value = HeaderValue::from_str(v);
            if name.is_err() || value.is_err() {
                return Err(Error::ParseError("http header parse failed".to_string()));
            }

            headers.insert(name.unwrap(), value.unwrap());
        }

        Ok(headers)
    }

    /// New LeetCode client
    pub fn new() -> Result<LeetCode, Error> {
        let default_headers =
            LeetCode::headers(
                HeaderMap::new(),
                vec![
                ("accept", "*/*"),
                ("accept-language", "zh-CN"),
                ("content-type", "application/json"),
                ("random-uuid", "ef1d1e54-7f59-2fa6-414b-065fc2d2a3c3"),
                (
                    "sec-ch-ua",
                    "Not/A)Brand\";v=\"99\", \"Google Chrome\";v=\"115\", \"Chromium\";v=\"115\"",
                ),
                ("sec-ch-ua-mobile", "?0"),
                ("sec-ch-ua-platform", "macOS"),
                ("sec-fetch-dest", "empty"),
                ("sec-fetch-mode", "cors"),
                ("sec-fetch-site", "same-origin"),
                // uuuserid: "30fa711aca0346830ccf87a43bb4d18c",
                ("x-csrftoken",
                  "pgit2LxmdvUsDvTirafHUwukw4Gf9AupqXS1vIoxOC5rJnfEOLvHwXl4YHqWif1o"),
                ("x-definition-name", "question"),("x-operation-name", "questionData"),
                ("x-timezone", "Asia/Shanghai"),
            ],
            )?;

        let client = ClientBuilder::new()
            .gzip(true)
            .connect_timeout(Duration::from_secs(30))
            .build()?;

        Ok(LeetCode {
            client,
            default_headers,
        })
    }

    /// Get specific problem detail
    pub async fn get_question_detail(&self, s: String) -> Result<Response, Error> {
        let slug = get_slug_from(&s)?;

        let mut json: Json = HashMap::new();
        json.insert(
            "query",
            vec![
                "query getQuestionDetail($titleSlug: String!) {",
                "  question(titleSlug: $titleSlug) {",
                "    questionId",
                "    title",
                "    content",
                "    stats",
                "    codeDefinition",
                "    sampleTestCase",
                "    exampleTestcases",
                "    enableRunCode",
                "    metaData",
                "    translatedContent",
                "  }",
                "}",
            ]
            .join("\n"),
        );

        json.insert(
            "variables",
            r#"{"titleSlug": "$titleSlug"}"#.replace("$titleSlug", slug.as_str()),
        );

        json.insert("operationName", "getQuestionDetail".to_string());

        let sstr = s.as_str();
        let url = get_request_url_from(sstr);

        Req {
            default_headers: self.default_headers.clone(),
            refer: Some(sstr.to_string()),
            info: false,
            json: Some(json),
            mode: Mode::Post,
            name: "get_problem_detail",
            url: url.to_string(),
        }
        .send(&self.client)
        .await
    }

    pub async fn get_code_snippets(&self, s: String) -> Result<Response, Error> {
        let slug = get_slug_from(&s)?;

        let mut json: Json = HashMap::new();
        json.insert(
            "query",
            vec![
                "query questionEditorData($titleSlug: String!) {",
                "   question(titleSlug: $titleSlug) {",
                "       questionId",
                "       questionFrontendId",
                "       codeSnippets {",
                "           lang",
                "           langSlug",
                "           code",
                "       }",
                "       envInfo",
                "       enableRunCode",
                "   }",
                "}",
            ]
            .join("\n"),
        );

        json.insert(
            "variables",
            r#"{"titleSlug": "$titleSlug"}"#.replace("$titleSlug", slug.as_str()),
        );

        json.insert("operationName", "questionEditorData".to_string());

        let sstr = s.as_str();
        let url = get_request_url_from(sstr);

        Req {
            default_headers: self.default_headers.clone(),
            refer: Some(sstr.to_string()),
            info: false,
            json: Some(json),
            mode: Mode::Post,
            name: "get_problem_detail",
            url: url.to_string(),
        }
        .send(&self.client)
        .await
    }
}

fn get_request_url_from(s: &str) -> &str {
    let url = if s.contains("leetcode.com") {
        "https://leetcode.com/graphql"
    } else {
        "https://leetcode.cn/graphql"
    };
    url
}

pub fn get_slug_from(s: &String) -> Result<String, Error> {
    let capture = regex::Regex::new(r"leetcode\.(com|cn)/problems/([a-zA-Z0-9\-]+)/?")
        .unwrap()
        .captures(s)
        .ok_or(Error::MatchError)?;
    let slug = &capture[2];
    Ok(slug.to_string())
}

/// Sub-module for leetcode, simplify requests
mod req {
    use super::Error;
    use super::LeetCode;
    use reqwest::{header::HeaderMap, Client, Response};
    use std::collections::HashMap;

    /// Standardize json format
    pub type Json = HashMap<&'static str, String>;

    /// Standardize request mode
    pub enum Mode {
        Get,
        Post,
    }

    /// LeetCode request prototype
    pub struct Req {
        pub default_headers: HeaderMap,
        pub refer: Option<String>,
        pub json: Option<Json>,
        pub info: bool,
        pub mode: Mode,
        pub name: &'static str,
        pub url: String,
    }

    impl Req {
        pub async fn send(self, client: &Client) -> Result<Response, Error> {
            println!("Running leetcode::{}...", &self.name);
            if self.info {
                println!("{}", &self.name);
            }
            let url = self.url.to_owned();
            let headers = LeetCode::headers(
                self.default_headers,
                vec![("Referer", &self.refer.unwrap_or(url))],
            )?;

            let req = match self.mode {
                Mode::Get => client.get(&self.url),
                Mode::Post => client.post(&self.url).json(&self.json),
            };

            Ok(req.headers(headers).send().await?)
        }
    }
}
