import os
import json
import requests
import re
import time
from datetime import datetime

repo_dir = os.path.dirname(os.path.abspath(__file__))
leetcode_dir = os.path.join(repo_dir, "leetcode")
cache_file = os.path.join(repo_dir, "metadata_cache.json")

url = "https://leetcode.com/graphql"

query_question = """
query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionId
    questionFrontendId
    title
    titleSlug
    difficulty
    topicTags {
      name
      slug
    }
  }
}
"""

query_user = """
query userProfile($username: String!) {
  matchedUser(username: $username) {
    submitStatsGlobal {
      acSubmissionNum {
        difficulty
        count
        submissions
      }
      totalSubmissionNum {
        difficulty
        count
        submissions
      }
    }
  }
}
"""

LANG_MAP = {
    ".cpp": "C++",
    ".js": "JavaScript",
    ".sql": "MySQL",
    ".py": "Python",
    ".py3": "Python",
    ".java": "Java",
    ".ts": "TypeScript",
    ".c": "C",
    ".cs": "C#",
    ".go": "Go",
    ".rs": "Rust",
    ".kt": "Kotlin",
    ".swift": "Swift"
}

def load_cache():
    if os.path.exists(cache_file):
        try:
            with open(cache_file, "r", encoding="utf-8") as f:
                return json.load(f)
        except Exception:
            pass
    return {}

def save_cache(cache):
    try:
        disk_cache = {}
        if os.path.exists(cache_file):
            try:
                with open(cache_file, "r", encoding="utf-8") as f:
                    disk_cache = json.load(f)
            except Exception:
                pass
        disk_cache.update(cache)
        with open(cache_file, "w", encoding="utf-8") as f:
            json.dump(disk_cache, f, indent=2)
    except Exception as e:
        print("Error saving cache:", e)

def folder_to_slug(folder_name):
    parts = folder_name.split("_", 1)
    if len(parts) < 2:
        return ""
    name_part = parts[1]
    s = name_part.lower().replace("_", "-")
    s = re.sub(r'[^a-z0-9\-]', '', s)
    s = re.sub(r'\-+', '-', s).strip('-')
    return s

def fetch_metadata(slug, cache):
    if slug in cache and cache[slug] and 'difficulty' in cache[slug]:
        return cache[slug]
    
    try:
        resp = requests.post(url, json={'query': query_question, 'variables': {'titleSlug': slug}}, headers={'User-Agent': 'Mozilla/5.0'}, timeout=10)
        if resp.status_code == 200:
            data = resp.json().get('data', {}).get('question')
            if data and data.get('titleSlug'):
                cache[slug] = data
                save_cache(cache)
                return data
    except Exception as e:
        print(f"Fetch error for {slug}:", e)
    return None

def fetch_user_accuracy(username="patel_jivan"):
    try:
        resp = requests.post(url, json={'query': query_user, 'variables': {'username': username}}, headers={'User-Agent': 'Mozilla/5.0'}, timeout=10)
        if resp.status_code == 200:
            data = resp.json().get('data', {}).get('matchedUser', {})
            stats = data.get('submitStatsGlobal', {})
            ac_list = {item['difficulty']: item for item in stats.get('acSubmissionNum', [])}
            tot_list = {item['difficulty']: item for item in stats.get('totalSubmissionNum', [])}
            
            ac_all = ac_list.get('All', {}).get('submissions', 0)
            tot_all = tot_list.get('All', {}).get('submissions', 0)
            overall_acc = (ac_all / tot_all * 100) if tot_all else 0.0

            ac_easy = ac_list.get('Easy', {}).get('submissions', 0)
            tot_easy = tot_list.get('Easy', {}).get('submissions', 0)
            easy_acc = (ac_easy / tot_easy * 100) if tot_easy else 0.0

            ac_med = ac_list.get('Medium', {}).get('submissions', 0)
            tot_med = tot_list.get('Medium', {}).get('submissions', 0)
            med_acc = (ac_med / tot_med * 100) if tot_med else 0.0

            ac_hard = ac_list.get('Hard', {}).get('submissions', 0)
            tot_hard = tot_list.get('Hard', {}).get('submissions', 0)
            hard_acc = (ac_hard / tot_hard * 100) if tot_hard else 0.0

            return {
                'overall_acc': overall_acc,
                'ac_all': ac_all,
                'tot_all': tot_all,
                'easy_acc': easy_acc,
                'ac_easy': ac_easy,
                'tot_easy': tot_easy,
                'med_acc': med_acc,
                'ac_med': ac_med,
                'tot_med': tot_med,
                'hard_acc': hard_acc,
                'ac_hard': ac_hard,
                'tot_hard': tot_hard
            }
    except Exception as e:
        print("User stats fetch error:", e)
    
    return {
        'overall_acc': 82.9,
        'ac_all': 966,
        'tot_all': 1165,
        'easy_acc': 87.2,
        'ac_easy': 695,
        'tot_easy': 797,
        'med_acc': 74.3,
        'ac_med': 260,
        'tot_med': 350,
        'hard_acc': 61.1,
        'ac_hard': 11,
        'tot_hard': 18
    }

def get_diff_badge(diff):
    d = (diff or 'Medium').lower()
    if d == 'easy':
        return '\U0001F7E2 Easy'
    elif d == 'medium':
        return '\U0001F7E1 Medium'
    elif d == 'hard':
        return '\U0001F534 Hard'
    return str(diff)

def main():
    cache = load_cache()
    if not os.path.exists(leetcode_dir):
        print(f"Directory {leetcode_dir} does not exist.")
        return

    folders = sorted([f for f in os.listdir(leetcode_dir) if os.path.isdir(os.path.join(leetcode_dir, f))])
    total_folders = len(folders)
    print(f"Processing {total_folders} solved question folders...")

    solved_questions = []
    
    for idx, folder in enumerate(folders, 1):
        parts = folder.split("_", 1)
        raw_id = parts[0]
        try:
            frontend_id = int(raw_id)
        except ValueError:
            frontend_id = 99999
        
        folder_path = os.path.join(leetcode_dir, folder)
        solution_files = [f for f in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, f))]
        
        slug = folder_to_slug(folder)
        meta = fetch_metadata(slug, cache)
        
        if not meta:
            clean_title = parts[1].replace("_", " ") if len(parts) > 1 else folder
            meta = {
                'questionFrontendId': str(frontend_id),
                'title': clean_title,
                'titleSlug': slug,
                'difficulty': 'Medium',
                'topicTags': []
            }
        
        langs = []
        file_map = {}
        for sfile in sorted(solution_files):
            ext = os.path.splitext(sfile)[1].lower()
            lang_name = LANG_MAP.get(ext, ext.strip('.').upper())
            file_rel_path = f"leetcode/{folder}/{sfile}"
            file_map[lang_name] = file_rel_path
            if lang_name not in langs:
                langs.append(lang_name)
        
        diff = meta.get('difficulty') or 'Medium'
        
        solved_questions.append({
            'folder': folder,
            'frontend_id': int(meta.get('questionFrontendId') or frontend_id),
            'title': meta.get('title') or parts[1].replace("_", " "),
            'titleSlug': meta.get('titleSlug') or slug,
            'difficulty': diff,
            'topicTags': meta.get('topicTags') or [],
            'languages': langs,
            'file_map': file_map
        })
        time.sleep(0.005)
    
    save_cache(cache)
    
    accuracy_stats = fetch_user_accuracy()
    
    solved_questions.sort(key=lambda x: x['frontend_id'])

    total_unique_questions = len(solved_questions)
    easy_count = sum(1 for q in solved_questions if (q['difficulty'] or '').lower() == 'easy')
    medium_count = sum(1 for q in solved_questions if (q['difficulty'] or '').lower() == 'medium')
    hard_count = sum(1 for q in solved_questions if (q['difficulty'] or '').lower() == 'hard')

    lang_counts = {}
    for q in solved_questions:
        for lang in q['languages']:
            lang_counts[lang] = lang_counts.get(lang, 0) + 1
    
    topic_map = {}
    for q in solved_questions:
        tags = q['topicTags']
        if not tags:
            tags = [{'name': 'Uncategorized', 'slug': 'uncategorized'}]
        for tag in tags:
            tname = tag.get('name') or 'Uncategorized'
            if tname not in topic_map:
                topic_map[tname] = []
            topic_map[tname].append(q)

    # 1. Generate README.md
    generate_readme_md(total_unique_questions, easy_count, medium_count, hard_count, lang_counts, topic_map, solved_questions, accuracy_stats)
    
    # 2. Generate ALL_SOLUTIONS.md
    generate_all_solutions_md(solved_questions)

    # 3. Generate TOPICS.md
    generate_topics_md(topic_map)

    print("Successfully generated README.md, ALL_SOLUTIONS.md, and TOPICS.md!")

def generate_readme_md(total, easy, medium, hard, lang_counts, topic_map, solved_questions, accuracy_stats):
    readme_path = os.path.join(repo_dir, "README.md")
    
    easy_pct = (easy / total * 100) if total else 0
    med_pct = (medium / total * 100) if total else 0
    hard_pct = (hard / total * 100) if total else 0

    easy_bar = "█" * int(easy_pct // 5) + "░" * (20 - int(easy_pct // 5))
    med_bar = "█" * int(med_pct // 5) + "░" * (20 - int(med_pct // 5))
    hard_bar = "█" * int(hard_pct // 5) + "░" * (20 - int(hard_pct // 5))

    acc_badge = f"![Accuracy](https://img.shields.io/badge/Accuracy-{accuracy_stats['overall_acc']:.1f}%25-blue?style=for-the-badge)"

    content = f"""# \U0001F680 LeetCode Solutions & Progress Dashboard

![LeetCode Total Solved](https://img.shields.io/badge/Total%20Solved-{total}-brightgreen?style=for-the-badge&logo=leetcode)
![Easy](https://img.shields.io/badge/Easy-{easy}-20B2AA?style=for-the-badge)
![Medium](https://img.shields.io/badge/Medium-{medium}-F0A830?style=for-the-badge)
![Hard](https://img.shields.io/badge/Hard-{hard}-E15554?style=for-the-badge)
{acc_badge}

Welcome to my personal **LeetCode Solutions Repository**! This automated repository contains all my solved algorithm and SQL problem solutions, organized cleanly with backdated commit history matching submission dates.

---

## \U0001F4CA Performance & Statistics Summary

### \U0001F3AF Accuracy & Difficulty Breakdown

| Difficulty | Solved Count | Percentage | Accepted Submissions | Total Submissions | Accuracy (Acceptance Rate) | Progress Bar |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| \U0001F7E2 **Easy** | **{easy}** | {easy_pct:.1f}% | {accuracy_stats['ac_easy']:,} | {accuracy_stats['tot_easy']:,} | **{accuracy_stats['easy_acc']:.1f}%** | `{easy_bar}` |
| \U0001F7E1 **Medium** | **{medium}** | {med_pct:.1f}% | {accuracy_stats['ac_med']:,} | {accuracy_stats['tot_med']:,} | **{accuracy_stats['med_acc']:.1f}%** | `{med_bar}` |
| \U0001F534 **Hard** | **{hard}** | {hard_pct:.1f}% | {accuracy_stats['ac_hard']:,} | {accuracy_stats['tot_hard']:,} | **{accuracy_stats['hard_acc']:.1f}%** | `{hard_bar}` |
| **Total** | **{total}** | **100%** | **{accuracy_stats['ac_all']:,}** | **{accuracy_stats['tot_all']:,}** | **{accuracy_stats['overall_acc']:.1f}%** | |

---

### \U0001F4BB Languages Used

| Language | Solved Questions | Percentage |
| :--- | :---: | :---: |
"""
    for lang, count in sorted(lang_counts.items(), key=lambda x: x[1], reverse=True):
        lpct = (count / total * 100) if total else 0
        content += f"| **{lang}** | {count} | {lpct:.1f}% |\n"

    content += """
---

## \U0001F4C2 Quick Navigation Directory

- \U0001F4D6 [**Browse All Solved Questions Catalog (`ALL_SOLUTIONS.md`)**](ALL_SOLUTIONS.md) - Complete numerical index of all solved problems.
- \U0001F3F7 [**Browse Questions by Topic (`TOPICS.md`)**](TOPICS.md) - Categorized problem sets by topic tags (Array, Dynamic Programming, Database, etc.).

---

## \U0001F525 Top Problem Topics

| Topic | Questions Solved | Easy | Medium | Hard |
| :--- | :---: | :---: | :---: | :---: |
"""
    sorted_topics = sorted(topic_map.items(), key=lambda x: len(x[1]), reverse=True)
    for tname, tquestions in sorted_topics[:10]:
        teasy = sum(1 for q in tquestions if (q['difficulty'] or '').lower() == 'easy')
        tmed = sum(1 for q in tquestions if (q['difficulty'] or '').lower() == 'medium')
        thard = sum(1 for q in tquestions if (q['difficulty'] or '').lower() == 'hard')
        content += f"| **{tname}** | {len(tquestions)} | {teasy} | {tmed} | {thard} |\n"

    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(content)

def generate_all_solutions_md(solved_questions):
    path = os.path.join(repo_dir, "ALL_SOLUTIONS.md")
    
    content = f"""# \U0001F4DA All Solved LeetCode Questions ({len(solved_questions)})

[\U0001F1E6 Back to Dashboard](README.md) | [View Questions by Topic \U0001F1E7](TOPICS.md)

| # | Problem Title | Difficulty | Solutions | Topics |
| :---: | :--- | :---: | :--- | :--- |
"""
    for q in solved_questions:
        fid = q.get('frontend_id') or 0
        fid_str = f"{fid:04d}"
        leetcode_url = f"https://leetcode.com/problems/{q['titleSlug']}/"
        title_link = f"[{q['title']}]({leetcode_url})"
        diff_badge = get_diff_badge(q['difficulty'])
        
        sol_links = []
        for lang_name, rel_path in q['file_map'].items():
            sol_links.append(f"[{lang_name}]({rel_path})")
        sol_str = ", ".join(sol_links)
        
        topic_names = [t.get('name', '') for t in q['topicTags'] if t.get('name')] if q['topicTags'] else []
        topic_str = ", ".join(f"`{t}`" for t in topic_names[:3])
        if len(topic_names) > 3:
            topic_str += f" *(+{len(topic_names)-3})*"
        
        content += f"| {fid_str} | {title_link} | {diff_badge} | {sol_str} | {topic_str} |\n"

    with open(path, "w", encoding="utf-8") as f:
        f.write(content)

def generate_topics_md(topic_map):
    path = os.path.join(repo_dir, "TOPICS.md")
    
    sorted_topics = sorted(topic_map.items(), key=lambda x: str(x[0]))
    
    content = f"""# \U0001F3F7 LeetCode Questions by Topic

[← Back to Dashboard](README.md) | [View Complete Solutions List →](ALL_SOLUTIONS.md)

## \U0001F4CC Topic Overview

| Topic Name | Total Solved | \U0001F7E2 Easy | \U0001F7E1 Medium | \U0001F534 Hard |
| :--- | :---: | :---: | :---: | :---: |
"""
    for tname, tq_list in sorted_topics:
        teasy = sum(1 for q in tq_list if (q.get('difficulty') or '').lower() == 'easy')
        tmed = sum(1 for q in tq_list if (q.get('difficulty') or '').lower() == 'medium')
        thard = sum(1 for q in tq_list if (q.get('difficulty') or '').lower() == 'hard')
        anchor = str(tname).lower().replace(" ", "-").replace("'", "").replace("(", "").replace(")", "")
        content += f"| [**{tname}**](#{anchor}) | {len(tq_list)} | {teasy} | {tmed} | {thard} |\n"

    content += "\n---\n\n"

    for tname, tq_list in sorted_topics:
        sorted_tq = sorted(tq_list, key=lambda x: (x.get('frontend_id') if isinstance(x.get('frontend_id'), int) else 999999))
        content += f"### \U0001F4CC {tname} ({len(tq_list)})\n\n"
        content += "| # | Problem Title | Difficulty | Solutions |\n"
        content += "| :---: | :--- | :---: | :--- |\n"
        for q in sorted_tq:
            fid = q.get('frontend_id') or 0
            fid_str = f"{fid:04d}"
            leetcode_url = f"https://leetcode.com/problems/{q['titleSlug']}/"
            title_link = f"[{q['title']}]({leetcode_url})"
            diff_badge = get_diff_badge(q['difficulty'])
            
            sol_links = []
            for lang_name, rel_path in q['file_map'].items():
                sol_links.append(f"[{lang_name}]({rel_path})")
            sol_str = ", ".join(sol_links)
            
            content += f"| {fid_str} | {title_link} | {diff_badge} | {sol_str} |\n"
        content += "\n[↑ Back to Top](#-leetcode-questions-by-topic)\n\n---\n\n"

    with open(path, "w", encoding="utf-8") as f:
        f.write(content)

if __name__ == "__main__":
    main()
