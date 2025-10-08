# import requests
# import json
# import time

# url = "https://leetcode.com/graphql/"

# query = """
# query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
#   problemsetQuestionList: questionList(
#     categorySlug: $categorySlug
#     limit: $limit
#     skip: $skip
#     filters: $filters
#   ) {
#     total: totalNum
#     questions: data {
#       frontendQuestionId: questionFrontendId
#       title
#       titleSlug
#       difficulty
#       paidOnly: isPaidOnly
#       acRate
#       status
#       freqBar
#       topicTags {
#         name
#         slug
#       }
#       hasSolution
#       hasVideoSolution
#     }
#   }
# }
# """

# headers = {
#     "Content-Type": "application/json",
#     "Referer": "https://leetcode.com",
#     "User-Agent": "Mozilla/5.0 (compatible; AymanFetcher/1.0)"
# }

# all_questions = []
# limit = 100
# skip = 0
# max_retries = 5

# while True:
#     payload = {
#         "query": query,
#         "variables": {
#             "categorySlug": "",
#             "limit": limit,
#             "skip": skip,
#             "filters": {}
#         }
#     }

#     for attempt in range(max_retries):
#         try:
#             response = requests.post(url, json=payload, headers=headers, timeout=15)
#             if response.status_code != 200:
#                 raise Exception(f"HTTP {response.status_code}")

#             data = response.json()
#             if "errors" in data:
#                 raise Exception(data["errors"])

#             qlist = data["data"]["problemsetQuestionList"]
#             questions = qlist["questions"]
#             total = qlist.get("total", None)

#             if not questions:
#                 raise ValueError("Empty question list returned")

#             all_questions.extend(questions)
#             skip += limit

#             print(f"Fetched {len(all_questions)} / {total}")

#             # break retry loop successfully
#             break

#         except Exception as e:
#             print(f"⚠️ Error at skip={skip}: {e}")
#             if attempt < max_retries - 1:
#                 wait = 5 * (attempt + 1)
#                 print(f"Retrying in {wait}s...")
#                 time.sleep(wait)
#             else:
#                 print("❌ Max retries reached, stopping.")
#                 break
#     else:
#         # If loop ended without break (all retries failed)
#         break

#     # stop if we have everything
#     if total and len(all_questions) >= total:
#         break

#     time.sleep(1.5)  # slower pacing to avoid rate-limit

# # Sort by frontendQuestionId
# all_questions.sort(key=lambda q: int(q["frontendQuestionId"]))

# with open("leetcode_questions.json", "w") as f:
#     json.dump(all_questions, f, indent=2)

# print(f"✅ Done. Total fetched: {len(all_questions)}")
import requests

URL = "https://leetcode.com/graphql/"

def get_question_starter_code(title_slug):
    query = """
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        title
        codeSnippets {
          lang
          langSlug
          code
        }
      }
    }
    """
    variables = {"titleSlug": title_slug}
    response = requests.post(URL, json={"query": query, "variables": variables})
    data = response.json()
    snippets = data["data"]["question"]["codeSnippets"]
    
    starter_code = {snippet["lang"]: snippet["code"] for snippet in snippets}
    return starter_code

# Example usage
title_slug = "two-sum"
starter_code = get_question_starter_code(title_slug)
for lang, code in starter_code.items():
    print(f"--- {lang} ---\n{code}\n")
