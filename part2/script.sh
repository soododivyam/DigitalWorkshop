#!/bin/bash

# Check if an assembly file name was provided
if [ -z "$1" ]; then
    echo "Error: Please provide the assembly file name as an argument."
    echo "Usage: $0 <filename.asm>"
    exit 1
fi

# --- Configuration ---
SOURCE_ASM="$1" # The first command-line argument (e.g., file1.asm)
BASE_NAME=$(basename "$SOURCE_ASM" .asm) # Extracts "file1" or "file2"
HEX_FILE="/home/ubuntu/DigitalWorkshop/part2/assembly/${BASE_NAME}.hex"             # Assumes avra generates file1.hex
DESTINATION_PATH="/home/ubuntu/DigitalWorkshop/part2/.pio/build/uno/" # **CHANGE THIS**
NEXT_COMMAND_FILE="firmware.hex"     # The fixed name the hex file should have in the destination

# --- Build Step (Run avra) ---
echo "Running avra on $SOURCE_ASM..."
avra "$SOURCE_ASM"

# Check if avra was successful
if [ $? -ne 0 ]; then
    echo "avra failed during compilation. Exiting."
    exit 1
fi

# --- Copy Step ---
echo "➡️  Copying $HEX_FILE to $DESTINATION_PATH$NEXT_COMMAND_FILE..."
cp "$HEX_FILE" "$DESTINATION_PATH$NEXT_COMMAND_FILE"

# Check if copy was successful
if [ $? -ne 0 ]; then
    echo "Copy failed. Exiting."
    exit 1
fi

# --- Run Next Command Step ---
echo "Successfully copied. Running the next command..."

# **CHANGE THE COMMAND BELOW to your actual next command**
pio run --target nobuild --target upload

# Check if the final command was successful
if [ $? -eq 0 ]; then
    echo " All commands executed successfully for $SOURCE_ASM!"
else
    echo " The final command failed. Check output above."
fi
