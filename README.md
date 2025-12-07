## Competitive Programming Starter

Minimal setup to spin up multiple C++ problem files from a single template and compile/run them quickly.

### What's inside
- `ready.sh`: Bash script that generates `a.cpp`, `b.cpp`, ... from `template.cpp` into a target folder.
- `template.cpp`: C++17 template with fast I/O and optional debug helpers (enabled unless `NDEBUG` is defined).

### Requirements
- Bash (macOS/Linux)
- `sed`
- `g++` with C++17 (e.g., `g++ (>=7)`)

### Generate problem files
Creates N files named `a.cpp`, `b.cpp`, ... in a new/existing folder, each based on `template.cpp` (or a custom template). The placeholder `{{PROBLEM}}` in the template (if present) is replaced with the letter.

```bash
# Usage
./ready.sh <number_of_problems> <folder_name> [template_file]

# Examples
./ready.sh 5 2025-10-20-codeforces
./ready.sh 8 round-900
./ready.sh 6 abc-contest-123 /path/to/custom_template.cpp
```

Notes:
- Maximum supported problems is 26 (`a`–`z`).
- Existing files are skipped (not overwritten).

### Compile and run
You can compile any generated file with C++17 and typical flags. Examples below assume you are inside the folder that contains `a.cpp`, `b.cpp`, etc.

```bash
# Debug build (debug helpers enabled)
g++ -std=gnu++17 -O2 -Wall -Wextra -Wshadow -Wconversion -DLOCAL a.cpp -o a && ./a < input.txt

# Release build (disable debug helpers by defining NDEBUG)
g++ -std=gnu++17 -O2 -DNDEBUG a.cpp -o a && ./a < input.txt

# Simple compile & run without extras
g++ -std=gnu++17 a.cpp -o a && ./a
```

Tip:
- Debug macros (`debug(...)`) and the scoped timer are compiled out when `NDEBUG` is defined.

### Typical workflow
```bash
cd /path/to/your/workdir
cp /Users/raiyan/code/github/cp/template.cpp .  # optional, if you want to customize per contest

# 1) Generate files for a contest
/Users/raiyan/code/github/cp/ready.sh 6 abc-contest-123

# 2) Solve problems inside the folder
cd abc-contest-123
# edit a.cpp, b.cpp, ...

# 3) Build and test a solution
g++ -std=gnu++17 -O2 -Wall a.cpp -o a
./a < sample_a.in > my_out.txt
```

### Customizing the template
- Edit `template.cpp` to add your preferred boilerplate (macros, utilities, etc.).
- Use the `{{PROBLEM}}` placeholder anywhere in the template to inject the problem letter in generated files.

### Troubleshooting
- "Template file 'template.cpp' not found": ensure you run the script from the directory that contains `template.cpp` (or provide a custom template path as the third argument).
- "Maximum supported problems is 26": the generator creates letters `a`–`z` only.
- If `g++` is missing, install Xcode Command Line Tools on macOS or your distro's build tools on Linux.


