# coding=utf-8
from __future__ import print_function, division, unicode_literals

import json
import glob
import os
import sys
import shutil

DIFFICULTIES = {
  "easy": "Fácil",
  "intermediate": "Intermediário",
  "hard": "Difícil",
  "facil": "Fácil",
  "intermediario": "Intermediário",
  "medium": "Intermediário",
  "medio": "Intermediário",
  "dificil": "Difícil"
}

REQUIRED = [
  "difficulty",
  "link",
  "category"
]

def get_difficulty(entry):
  return DIFFICULTIES[entry["difficulty"]]

def get_link(entry):
  if "name" not in entry:
    return "[%s](%s)" % (entry["link"], entry["link"])
  else:
    return "[%s](%s)" % (entry["name"], entry["link"])

def get_tips_from_array(tips):
  if len(tips) == 0:
    return ""
  else:
    return "<details><summary>mostrar</summary>%s%s</details>" % (tips[0], get_tips_from_array(tips[1:]))

def get_tips(entry):
  if "tips" not in entry:
    return "-"
  
  if not isinstance(entry["tips"], list):
    return get_tips_from_array([entry["tips"]])
  else:
    return get_tips_from_array(entry["tips"])

def get_problem_code_from_desc(path):
  return os.path.basename(os.path.dirname(path))

def get_problem_dir_from_desc(path):
  return os.path.dirname(path)

def get_camel(s):
  return s.replace("-", " ").title().replace(" ", "")

def get_category_name(s):
  return s.replace("-", " ").title()

def get_category_folder(cat):
  return "./Problemas/%s/" % (cat)

def dump_headers(f, arr):
  arr = [""] + arr + [""]
  f.write(("|".join(arr) + "\n").encode("utf-8"))
  f.write(("|".join(map(lambda x: "-" if len(x) > 0 else "", arr)) + "\n").encode("utf-8"))

def dump_row(f, arr):
  arr = [""] + arr + [""]
  f.write(("|".join(arr) + "\n").encode("utf-8"))

def dump(f, entries):
  if len(entries) == 0:
    f.write("_Nenhum problema nesta dificuldade._\n")
  else:
    dump_headers(f, ["#", "Cód.", "Link", "Dicas", "Soluções e Discussão"])

    for entry in entries:
      dump_row(f, ["", entry["code"], get_link(entry), get_tips(entry), "[abrir](../.data/%s)" % get_problem_code_from_desc(entry["desc"])])
  
  f.write("\n")

print("Removing old categories...")

for category_folder in glob.glob("./Problemas/[A-Z]*/"):
  print(category_folder)
  # shutil.rmtree(category_folder)

print("Building project...")

descs = sorted(glob.glob("./Problemas/.data/*/desc.json"), key=lambda x: get_problem_code_from_desc(x))

seen_links = {}
categories = {}

for desc in descs:
  with open(desc) as desc_json:
    data = json.load(desc_json)
    
    failed = False
    for req in REQUIRED:
      if req not in data:
        print("Field %s is required in %s" % (req, desc))
        failed = True

    if failed:
      continue

    data["link"] = data["link"].strip()
    if data["link"] in seen_links:
      print("Link from %s was already added before at %s", desc, seen_links[data["link"]])
      continue
    
    seen_links[data["link"]] = desc
  
    data["desc"] = desc
    data["code"] = get_problem_code_from_desc(desc)

    current_categories = map(get_camel, data["category"]) if isinstance(data["category"], list) else [get_camel(data["category"])]

    for current_category in current_categories:
      if current_category not in categories:
        categories[current_category] = {
          "name": get_category_name(data["category"]),
          "entries": [data]
        }
      else:
        categories[current_category]["entries"].append(data)

for (category, data) in list(categories.items()):
  category_name = data["name"]
  entries = data["entries"]

  readme = os.path.join(get_category_folder(category), "README.md")

  with open(readme, "w") as f:
    f.write("## %s\n" % category_name)
    f.write("\n")

    f.write("### Fácil\n".encode("utf-8"))
    dump(f, filter(lambda x: get_difficulty(x) == "Fácil", entries))

    f.write("### Intermediário\n".encode("utf-8"))
    dump(f, filter(lambda x: get_difficulty(x) == "Intermediário", entries))

    f.write("### Difícil\n".encode("utf-8"))
    dump(f, filter(lambda x: get_difficulty(x) == "Difícil", entries))
