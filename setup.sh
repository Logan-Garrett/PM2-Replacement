#!/bin/bash

task_master_comment="# Path to Task Master installation."
task_master_config="export PATH=$PATH:/home/logan/Desktop/git/PM2-Replacement"

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

