import os
import sys
import time
import datetime
import subprocess
import requests
import json
import re

# Extension mapping for programming languages
LANG_EXT_MAP = {
    'cpp': 'cpp',
    'c++': 'cpp',
    'java': 'java',
    'python': 'py',
    'python3': 'py',
    'py': 'py',
    'python3-pure': 'py',
    'c': 'c',
    'csharp': 'cs',
    'cs': 'cs',
    'javascript': 'js',
    'js': 'js',
    'typescript': 'ts',
    'ts': 'ts',
    'ruby': 'rb',
    'swift': 'swift',
    'golang': 'go',
    'go': 'go',
    'scala': 'scala',
    'kotlin': 'kt',
    'rust': 'rs',
    'php': 'php',
    'sql': 'sql',
    'mysql': 'sql',
    'mssql': 'sql',
    'oraclesql': 'sql',
    'postgresql': 'sql',
    'racket': 'rkt',
    'erlang': 'erl',
    'elixir': 'ex',
    'dart': 'dart',
    'bash': 'sh'
}

GRAPHQL_URL = "https://leetcode.com/graphql"

SUBMISSIONS_QUERY = """
query submissionList($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String) {
  submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {
    lastKey
    hasNext
    submissions {
      id
      title
      titleSlug
      statusDisplay
      lang
      runtime
      timestamp
      url
      isPending
      memory
    }
  }
}
"""

SUBMISSION_DETAIL_QUERY = """
query submissionDetails($submissionId: Int!) {
  submissionDetails(submissionId: $submissionId) {
    code
    timestamp
    statusCode
    statusDisplay
    lang {
      name
      verboseName
    }
    question {
      questionId
      questionFrontendId
      title
      titleSlug
    }
  }
}
"""

def sanitize_filename(name):
    # Remove invalid characters for directory/file names
    clean_name = re.sub(r'[\\/*?:"<>|]', '', name)
    clean_name = clean_name.replace(' ', '_')
    clean_name = re.sub(r'_+', '_', clean_name)
    return clean_name.strip('_')

def format_question_folder(frontend_id, title):
    # Format frontend_id to 4 digits if numeric
    try:
        num = int(frontend_id)
        formatted_id = f"{num:04d}"
    except (ValueError, TypeError):
        formatted_id = str(frontend_id)
    
    clean_title = sanitize_filename(title)
    return f"{formatted_id}_{clean_title}"

def get_headers(session_cookie, csrf_token=""):
    headers = {
        "Content-Type": "application/json",
        "Referer": "https://leetcode.com",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
        "Cookie": f"LEETCODE_SESSION={session_cookie}; csrftoken={csrf_token};"
    }
    if csrf_token:
        headers["x-csrftoken"] = csrf_token
    return headers

def fetch_all_accepted_submission_ids(session_cookie, csrf_token=""):
    headers = get_headers(session_cookie, csrf_token)
    offset = 0
    limit = 20
    has_next = True
    
    # Store latest submission per (titleSlug, lang)
    latest_submissions = {}
    total_scanned = 0

    print("Fetching submission list from LeetCode...", flush=True)

    while has_next:
        variables = {
            "offset": offset,
            "limit": limit,
            "lastKey": None,
            "questionSlug": ""
        }
        
        try:
            resp = requests.post(GRAPHQL_URL, json={"query": SUBMISSIONS_QUERY, "variables": variables}, headers=headers, timeout=15)
            if resp.status_code != 200:
                print(f"Error fetching submissions list HTTP {resp.status_code}: {resp.text}", flush=True)
                break
            
            data = resp.json()
            if "errors" in data:
                print(f"GraphQL error fetching submissions list: {data['errors']}", flush=True)
                break
            
            sub_list = data.get("data", {}).get("submissionList", {})
            submissions = sub_list.get("submissions", [])
            has_next = sub_list.get("hasNext", False)
            
            if not submissions:
                break
            
            for sub in submissions:
                total_scanned += 1
                status = sub.get("statusDisplay", "")
                if status.lower() == "accepted":
                    slug = sub.get("titleSlug")
                    lang = sub.get("lang")
                    timestamp = int(sub.get("timestamp", 0))
                    
                    key = (slug, lang)
                    if key not in latest_submissions or timestamp > latest_submissions[key]["timestamp"]:
                        latest_submissions[key] = {
                            "id": int(sub["id"]),
                            "titleSlug": slug,
                            "lang": lang,
                            "timestamp": timestamp,
                            "title": sub.get("title")
                        }
            
            offset += limit
            print(f"Scanned {total_scanned} submissions, found {len(latest_submissions)} unique accepted (latest per lang)...", flush=True)
            time.sleep(0.5)  # Rate limiting delay
            
        except Exception as e:
            print(f"\nException while fetching submission list: {e}", flush=True)
            break

    print(f"\nTotal submissions scanned: {total_scanned}", flush=True)
    print(f"Total unique (Question, Language) latest accepted solutions found: {len(latest_submissions)}", flush=True)
    return list(latest_submissions.values())

def fetch_submission_detail(sub_id, session_cookie, csrf_token=""):
    headers = get_headers(session_cookie, csrf_token)
    variables = {"submissionId": sub_id}
    
    try:
        resp = requests.post(GRAPHQL_URL, json={"query": SUBMISSION_DETAIL_QUERY, "variables": variables}, headers=headers, timeout=15)
        if resp.status_code != 200:
            print(f"Error fetching detail for submission {sub_id}: HTTP {resp.status_code}")
            return None
        
        data = resp.json()
        if "errors" in data:
            print(f"GraphQL error fetching submission {sub_id}: {data['errors']}")
            return None
        
        detail = data.get("data", {}).get("submissionDetails")
        return detail
    except Exception as e:
        print(f"Exception fetching submission detail {sub_id}: {e}")
        return None

def setup_git_repo(repo_dir):
    # Initialize git repository if not already initialized
    git_dir = os.path.join(repo_dir, ".git")
    if not os.path.exists(git_dir):
        print("Initializing git repository...")
        subprocess.run(["git", "init"], cwd=repo_dir, check=True)
        # Check if user.name or user.email are set
        try:
            subprocess.run(["git", "config", "user.name"], cwd=repo_dir, check=True, stdout=subprocess.DEVNULL)
        except subprocess.CalledProcessError:
            subprocess.run(["git", "config", "user.name", "LeetCode Automator"], cwd=repo_dir, check=True)
        try:
            subprocess.run(["git", "config", "user.email"], cwd=repo_dir, check=True, stdout=subprocess.DEVNULL)
        except subprocess.CalledProcessError:
            subprocess.run(["git", "config", "user.email", "leetcode@localhost"], cwd=repo_dir, check=True)

def commit_solution(repo_dir, folder_name, filename, code, timestamp, frontend_id, title, lang_name):
    folder_path = os.path.join(repo_dir, "leetcode", folder_name)
    os.makedirs(folder_path, exist_ok=True)
    
    file_path = os.path.join(folder_path, filename)
    with open(file_path, "w", encoding="utf-8") as f:
        f.write(code)
    
    # Format date for git commit
    # Git ISO timestamp format: YYYY-MM-DDTHH:MM:SS
    dt = datetime.datetime.fromtimestamp(timestamp, tz=datetime.timezone.utc)
    git_date_str = dt.strftime("%Y-%m-%dT%H:%M:%S+0000")
    
    rel_file_path = os.path.relpath(file_path, repo_dir)
    
    # Git Add
    subprocess.run(["git", "add", rel_file_path], cwd=repo_dir, check=True)
    
    # Check if there are changes to commit
    status_res = subprocess.run(["git", "status", "--porcelain", rel_file_path], cwd=repo_dir, capture_output=True, text=True)
    if not status_res.stdout.strip():
        # No changes to commit
        return False

    commit_msg = f"Add solution for {frontend_id}. {title} ({lang_name})"
    
    env = os.environ.copy()
    env["GIT_AUTHOR_DATE"] = git_date_str
    env["GIT_COMMITTER_DATE"] = git_date_str
    
    subprocess.run(["git", "commit", "-m", commit_msg], cwd=repo_dir, env=env, check=True)
    return True

def main():
    repo_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
    
    session_cookie = os.environ.get("LEETCODE_SESSION", "").strip()
    csrf_token = os.environ.get("LEETCODE_CSRF", "").strip()

    if not session_cookie:
        print("LEETCODE_SESSION cookie is required.")
        if len(sys.argv) > 1:
            session_cookie = sys.argv[1].strip()
        if len(sys.argv) > 2:
            csrf_token = sys.argv[2].strip()

    if not session_cookie:
        print("Please provide LEETCODE_SESSION as an environment variable or argument.")
        sys.exit(1)

    setup_git_repo(repo_dir)

    target_submissions = fetch_all_accepted_submission_ids(session_cookie, csrf_token)
    if not target_submissions:
        print("No accepted submissions found or failed to fetch.")
        return

    # Sort target submissions chronologically by timestamp (oldest first)
    target_submissions.sort(key=lambda x: x["timestamp"])

    print(f"\nFetching detailed code and committing {len(target_submissions)} latest solutions chronologically...", flush=True)
    
    committed_count = 0
    for idx, item in enumerate(target_submissions, 1):
        sub_id = item["id"]
        print(f"[{idx}/{len(target_submissions)}] Fetching submission {sub_id} ({item['titleSlug']} - {item['lang']})...", flush=True)
        
        detail = fetch_submission_detail(sub_id, session_cookie, csrf_token)
        if not detail:
            print(f"  Skipping {sub_id} due to fetch failure.", flush=True)
            continue
        
        code = detail.get("code")
        question = detail.get("question", {})
        frontend_id = question.get("questionFrontendId") or "0"
        title = question.get("title") or item.get("title") or item.get("titleSlug")
        
        lang_obj = detail.get("lang")
        if isinstance(lang_obj, dict):
            lang_name = lang_obj.get("name", item["lang"])
            verbose_lang = lang_obj.get("verboseName", lang_name)
        else:
            lang_name = str(lang_obj or item["lang"])
            verbose_lang = lang_name

        ext = LANG_EXT_MAP.get(lang_name.lower(), lang_name.lower())
        filename = f"solution.{ext}"
        folder_name = format_question_folder(frontend_id, title)
        timestamp = int(detail.get("timestamp") or item["timestamp"])
        
        committed = commit_solution(repo_dir, folder_name, filename, code, timestamp, frontend_id, title, verbose_lang)
        if committed:
            committed_count += 1
            print(f"  Committed: {folder_name}/{filename} with date {datetime.datetime.fromtimestamp(timestamp, tz=datetime.timezone.utc)}", flush=True)
        else:
            print(f"  Already up to date: {folder_name}/{filename}", flush=True)

        time.sleep(0.5)  # Rate limiting delay

    print(f"\nSuccess! Committed {committed_count} solution files to Git with matching submission timestamps.", flush=True)
    
    print("\nUpdating README.md, ALL_SOLUTIONS.md, and TOPICS.md...", flush=True)
    try:
        import generate_readme
        generate_readme.main()
    except Exception as e:
        print("Error updating documentation:", e, flush=True)

if __name__ == "__main__":
    main()
