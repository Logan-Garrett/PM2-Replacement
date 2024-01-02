#!/bin/bash

setup_file_path=$(readlink -f "$0")
directory_name=$(dirname "$setup_file_path")

task_master_comment="# Path to Task Master installation."
task_master_config="export PATH=$PATH:$directory_name"

# Check if the line already exists in .zshrc
if ! grep -qF "$task_master_config" ~/.zshrc; then
    # If not, add the line to .zshrc
    echo "$task_master_comment" >> ~/.zshrc
    echo "$task_master_config" >> ~/.zshrc
    echo "Updated .zshrc with the new configuration."
else
    # If the line already exists, notify that no update was needed
    echo "No changes needed. Line already exists in .zshrc."
fi

source ~/.zshrc
