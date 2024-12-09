if [ -x ./sleep-tracker ]; then
    echo "File already exists."
else
    echo "File does not exist. Downloading from github"
    curl -O https://raw.githubusercontent.com/JasonEl1/sleep-tracker/master/sleep-tracker
    echo "Downloaded file."
fi

alias_entry="alias sleeptracker=$(pwd)/sleep-tracker"

if grep -q "$alias_entry" ~/.zshrc; then
    echo "Alias already exists."
else
    echo "$alias_entry" >> ~/.zshrc
    echo "Created alias 'sleeptracker' in ~/.zshrc."
    source ~/.zshrc
    exit
fi
