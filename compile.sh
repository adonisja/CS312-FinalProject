#!/bin/bash

# Check if source file is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <source_file> [output_file]"
  exit 1
fi

SOURCE_FILE=$1
OUTPUT_FILE=${2:-a.out}  # This will use second argument if provided, else default to "a.out"

# Print the source file path
echo "Compiling: $SOURCE_FILE -> $OUTPUT_FILE"

# Compile the source file with C++11 standard
g++ -std=c++17 "$SOURCE_FILE" -o "$OUTPUT_FILE"

# Check if compilation was successful
if [ $? -eq 0 ]; then
  echo "Successfully compiled $OUTPUT_FILE"
  echo "Now running the program..."
  echo "--------------------------------------"
  ./"$OUTPUT_FILE"
  echo "--------------------------------------"
  # Delete the output file after execution
  rm "$OUTPUT_FILE"
  echo "$OUTPUT_FILE was deleted."
else
  echo "Compilation failed."
  exit 2
fi
