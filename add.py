import build
import os
import sys
import json

try: input = raw_input
except NameError: pass

if len(sys.argv) < 2:
    print("The first argument must be the link for your problem.")
    sys.exit(1)

link = sys.argv[1].strip()

for i in range(1, 1000000):
    path = "./Problemas/.data/%d/" % i
    if os.path.exists(path):
        continue

    print("The code of your new problem will be %d" % i)
    name = input("Problem Name: ").strip()

    categories = map(lambda x: x.strip(), input("Categories (comma-separated): ").split(","))

    difficulty = input("Difficulty (easy/intermediate/hard): ").strip().lower()
    if difficulty not in build.DIFFICULTIES:
        print("Invalid difficulty!")
        sys.exit(1)

    build.ensure_dir(os.path.join(path, "desc.json"))
    with open(os.path.join(path, "desc.json"), "w") as f:
        res = {
            "name": name,
            "category": map(build.get_category_name, categories),
            "link": link,
            "difficulty": difficulty
        }


        f.write(json.dumps(res, sort_keys=True, indent=4, separators=(',', ': ')))

    break
