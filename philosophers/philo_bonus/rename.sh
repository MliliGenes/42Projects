#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

DIRECTORY="$1"

if [ ! -d "$DIRECTORY" ]; then
    echo "Error: Directory '$DIRECTORY' does not exist"
    exit 1
fi

rename_to_bonus() {
    local file="$1"
    local dir=$(dirname "$file")
    local base=$(basename "$file")
    local name="${base%.*}"
    local ext="${base##*.}"
    local new_name="${dir}/${name}_bonus.${ext}"
    
    echo "Renaming $file to $new_name"
    mv "$file" "$new_name"
}

echo "Renaming .c files..."
find "$DIRECTORY" -type f -name "*.c" | while read file; do
    rename_to_bonus "$file"
done

echo "Renaming .h files..."
find "$DIRECTORY" -type f -name "*.h" | while read file; do
    rename_to_bonus "$file"
done

echo "Done!"