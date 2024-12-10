Keep track of how much sleep you get every night with a single terminal command. Data is stored in a local .txt file for analysis.

### MacOS Setup

Before use, `main.cpp` must first be compiled. This can be done by either running 'bash setup.sh' to download the executable from github or compiling the file manually. `setup.sh` will also add an alias for the program in ~/.zshrc for now, by default named `sleep-tracker`.

### Usage

In the terminal, enter `sleep-tracker`. Enter the time you went to sleep and when you woke up. Your total hours of sleep will be calculated, and stored in a local .txt file named `sleep_data.txt`.
