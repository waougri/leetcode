import os
import json
import requests
from random import choice
from sys import argv
import webbrowser
from colorama import init, Fore, Style

# ---------- INIT COLORAMA ----------
init(autoreset=True)

# ---------- CONFIG ----------
LANGS = {
    "C++": ".cc",
    "Java": ".java",
    "Python3": ".py",
    "JavaScript": ".js",
    "TypeScript": ".ts",
    "C#": ".cs",
    "C": ".c",
    "Go": ".go",
    "Kotlin": ".kt",
    "Rust": ".rs",
    "Ruby": ".rb",
    "PHP": ".php",
    "Dart": ".dart",
    "Scala": ".scala",
    "Elixir": ".ex",
    "Erlang": ".erl",
    "Racket": ".rkt",
}

URL = "https://leetcode.com/graphql/"

# ---------- HELPERS ----------
def suggest_random_lang() -> str:
    return choice(list(LANGS.keys()))

def title_to_file_name(problem_name: str) -> str:
    return problem_name.lower().strip().replace(" ", "_")

def title_to_leetcode(pb_name: str) -> str:
    return pb_name.lower().strip().replace(" ", "-")

def split_problem_name(full_title: str) -> tuple[str, str]:
    pb_number, pb_name = full_title.split('.', 1)
    return pb_number.strip(), pb_name.strip()

def open_problem(leetcode_formatted_pb_name: str):
    url = f"https://leetcode.com/problems/{leetcode_formatted_pb_name}/"
    print(Fore.CYAN + f"Opening problem page: {url}")
    webbrowser.open_new(url)

def get_question_starter_code(title_slug: str) -> dict[str, str]:
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
    return {snippet["lang"]: snippet["code"] for snippet in snippets}

def create_file_and_dir(pb_number: str, pb_name: str, file_ext: str, starter_code: str) -> None:
    os.makedirs(pb_number, exist_ok=True)
    file_path = os.path.join(pb_number, f"{pb_name}{file_ext}")
    with open(file_path, "w") as f:
        f.write(starter_code)
    print(Fore.GREEN + f"[✓] Created file {file_path}")

def log_info(message: str):
    print(Fore.BLUE + "[*] " + Style.BRIGHT + message)

def log_warning(message: str):
    print(Fore.YELLOW + "[!] " + Style.BRIGHT + message)

def log_error(message: str):
    print(Fore.RED + "[✗] " + Style.BRIGHT + message)

# ---------- MAIN ----------
def main():
    log_info(f"Current working directory: {os.getcwd()}")

    if len(argv) != 2:
        log_error("Usage: python create_problem.py <problem_number>")
        return

    pb_number = argv[1]

    # Load questions
    try:
        with open("leetcode_questions.json") as f:
            questions = json.load(f)
    except Exception as e:
        log_error(f"Failed to read leetcode_questions.json: {e}")
        return

    # Find problem by number
    problem_data = next((q for q in questions if q["frontendQuestionId"] == pb_number), None)
    if not problem_data:
        log_warning(f"Problem #{pb_number} not found in JSON.")
        return

    pb_name = title_to_file_name(problem_data["title"])
    lang = suggest_random_lang()
    file_ext = LANGS[lang]

    log_info(f"Selected language: {Fore.MAGENTA}{lang}")
    log_info(f"Problem: {Fore.CYAN}{problem_data['title']} (#{pb_number})")

    # Get starter code
    try:
        starter_codes = get_question_starter_code(problem_data["titleSlug"])
        starter_code = starter_codes.get(lang, f"# Starter code for {lang} not found\n")
    except Exception as e:
        log_warning(f"Failed to fetch starter code from LeetCode: {e}")
        starter_code = f"# Starter code for {lang} not found\n"

    # Create folder & file
    create_file_and_dir(pb_number, pb_name, file_ext, starter_code)

    # Open in browser
    open_problem(problem_data["titleSlug"])
    log_info("Done! Happy coding 🤘")

if __name__ == "__main__":
    main()
