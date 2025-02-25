#!/usr/bin/env bash

usage() {
    echo "Usage: $0 [-d | --dry] <folder_path>"
    echo "  -d, --dry     Preview changes without renaming files"
    echo "  -h, --help    Show this help message"
    exit 0
}

# Default values
dry_run=false

# Parse arguments
while [[ $# -gt 0 ]]; do
    case "$1" in
        -d|--dry)
            dry_run=true
            shift
            ;;
        -h|--help)
            usage
            ;;
        *)
            folder="$1"
            shift
            ;;
    esac
done

# Validate folder path
if [[ -z "$folder" ]]; then
    echo "Error: Missing folder path."
    usage
fi

if [[ ! -d "$folder" ]]; then
    echo "Error: '$folder' is not a valid directory."
    exit 1
fi

# Get the highest number in the filenames (fix for macOS)
max_num=$(ls "$folder" | grep -Eo '^[0-9]+' | sort -nr | head -n 1)
if [[ -z "$max_num" ]]; then
    echo "No matching files found in '$folder'."
    exit 1
fi

# Determine required zero padding
num_digits=${#max_num}

# Rename files with correct leading zeros
for file in "$folder"/*; do
    filename=$(basename "$file")
    if [[ $filename =~ ^([0-9]+)_(.*) ]]; then
        num=${BASH_REMATCH[1]}
        rest=${BASH_REMATCH[2]}

        # Convert number to decimal to remove leading zeros
        num=$((10#$num))

        # Format with correct leading zeros
        new_name=$(printf "%0${num_digits}d_%s" "$num" "$rest")

        if [[ "$filename" != "$new_name" ]]; then
            if $dry_run; then
                echo "Would rename: '$filename' -> '$new_name'"
            else
                mv -v "$file" "$folder/$new_name"
            fi
        fi
    fi
done

echo "Renaming completed."
