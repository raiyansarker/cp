#!/bin/bash

# Check arguments
if [ $# -lt 2 ]; then
  echo "Usage: $0 <number_of_problems> <folder_name>"
  exit 1
fi

num=$1
folder=$2
template_file="template.cpp"

# Validate number of problems
if ! [[ "$num" =~ ^[0-9]+$ ]]; then
  echo "Error: First argument must be a positive integer."
  exit 1
fi

if [ "$num" -gt 26 ]; then
  echo "Error: Maximum supported problems is 26 (a–z)."
  exit 1
fi

# Check if template file exists
if [ ! -f "$template_file" ]; then
  echo "Error: Template file '$template_file' not found."
  exit 1
fi

# Create folder if it doesn't exist
mkdir -p "$folder"

# Alphabet array
alphabet=( {a..z} )

# Create files using template
for (( i=0; i<num; i++ )); do
  filename="$folder/${alphabet[$i]}.cpp"
  if [ -e "$filename" ]; then
    echo "Skipping $filename (already exists)"
  else
    # Replace placeholder {{PROBLEM}} with the letter
    sed "s/{{PROBLEM}}/${alphabet[$i]}/g" "$template_file" > "$filename"
    echo "Created $filename"
  fi
done

# Optional: open all files in VS Code Insiders
# code-insiders "$folder"

