fetch("https://leetcode.cn/graphql/", {
  headers: {
    accept: "*/*",
    "accept-language": "zh-CN",
    "content-type": "application/json",
    "random-uuid": "ef1d1e54-7f59-2fa6-414b-065fc2d2a3c3",
    "sec-ch-ua":
      '"Not/A)Brand";v="99", "Google Chrome";v="115", "Chromium";v="115"',
    "sec-ch-ua-mobile": "?0",
    "sec-ch-ua-platform": '"macOS"',
    "sec-fetch-dest": "empty",
    "sec-fetch-mode": "cors",
    "sec-fetch-site": "same-origin",
    // uuuserid: "30fa711aca0346830ccf87a43bb4d18c",
    "x-csrftoken":
      "pgit2LxmdvUsDvTirafHUwukw4Gf9AupqXS1vIoxOC5rJnfEOLvHwXl4YHqWif1o",
    "x-definition-name": "question",
    "x-operation-name": "questionData",
    "x-timezone": "Asia/Shanghai",
  },
  referrer: "https://leetcode.cn/",
  referrerPolicy: "strict-origin-when-cross-origin",
  body: '{"operationName":"questionData","variables":{"titleSlug":"two-sum"},"query":"query questionData($titleSlug: String!) {\\n  question(titleSlug: $titleSlug) {\\n    questionId\\n    questionFrontendId\\n    categoryTitle\\n    boundTopicId\\n    title\\n    titleSlug\\n    content\\n    translatedTitle\\n    translatedContent\\n    isPaidOnly\\n    difficulty\\n    likes\\n    dislikes\\n    isLiked\\n    similarQuestions\\n    contributors {\\n      username\\n      profileUrl\\n      avatarUrl\\n      __typename\\n    }\\n    langToValidPlayground\\n    topicTags {\\n      name\\n      slug\\n      translatedName\\n      __typename\\n    }\\n    companyTagStats\\n    codeSnippets {\\n      lang\\n      langSlug\\n      code\\n      __typename\\n    }\\n    stats\\n    hints\\n    solution {\\n      id\\n      canSeeDetail\\n      __typename\\n    }\\n    status\\n    sampleTestCase\\n    metaData\\n    judgerAvailable\\n    judgeType\\n    mysqlSchemas\\n    dataSchemas\\n    enableRunCode\\n    envInfo\\n    book {\\n      id\\n      bookName\\n      pressName\\n      source\\n      shortDescription\\n      fullDescription\\n      bookImgUrl\\n      pressImgUrl\\n      productUrl\\n      __typename\\n    }\\n    isSubscribed\\n    isDailyQuestion\\n    dailyRecordStatus\\n    editorType\\n    ugcQuestionId\\n    style\\n    exampleTestcases\\n    jsonExampleTestcases\\n    __typename\\n  }\\n}\\n"}',
  method: "POST",
  mode: "cors",
  credentials: "include",
})
  .then((res) => {
    return res.json()
  })
  .then((res) => {
    console.log(res)
  })
  .catch((err) => {
    console.log(err)
  })
  .finally(() => {
    console.log("finally")
  })
// fetch("https://leetcode.cn/graphql/", {
//   headers: {
//     accept: "*/*",
//     "accept-language": "zh-CN,zh;q=0.9,en;q=0.8",
//     authorization: "",
//     baggage:
//       "sentry-environment=production,sentry-release=SgEyqAQP8f2cvz9vitHX6,sentry-transaction=%2Fproblems%2F%5Bslug%5D%2F%5B%5B...tab%5D%5D,sentry-public_key=767ac77cf33a41e7832c778204c98c38,sentry-trace_id=2f7c2bd434a7423697b34a59fac8911a,sentry-sample_rate=0.03",
//     "content-type": "application/json",
//     // "random-uuid": "912f6ced-03a0-844b-6028-dd54097ecae6",
//     "sec-ch-ua":
//       '"Not/A)Brand";v="99", "Google Chrome";v="115", "Chromium";v="115"',
//     "sec-ch-ua-mobile": "?0",
//     "sec-ch-ua-platform": '"macOS"',
//     "sec-fetch-dest": "empty",
//     "sec-fetch-mode": "cors",
//     "sec-fetch-site": "same-origin",
//     "sentry-trace": "2f7c2bd434a7423697b34a59fac8911a-b3266a0e974d2169-0",
//     "x-csrftoken":
//       "QQ03G79uZI5VuajLrdnCCUhrO1J0VVmKcAfkqR8B4VTQhmkjMu1h4lJw0D6cHAts",
//   },
//   referrer: "https://leetcode.cn/problems/two-sum/",
//   referrerPolicy: "strict-origin-when-cross-origin",
//   body: '{"query":"\\n    query questionEditorData($titleSlug: String!) {\\n  question(titleSlug: $titleSlug) {\\n    questionId\\n    questionFrontendId\\n    codeSnippets {\\n      lang\\n      langSlug\\n      code\\n    }\\n    envInfo\\n    enableRunCode\\n  }\\n}\\n    ","variables":{"titleSlug":"two-sum"},"operationName":"questionEditorData"}',
//   method: "POST",
//   mode: "cors",
//   credentials: "include",
// })
//   .then((res) => {
//     return res.json()
//   })
//   .then((res) => {
//     // let snippets = res.data.question.codeSnippets
//     console.log(res)
//   })
//   .catch((err) => {
//     console.log(err)
//   })
//   .finally(() => {
//     console.log("finally")
//   })
