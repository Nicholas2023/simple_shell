# 0x16. C - Simple Shell

---
## Introduction
---
This is a simple shell project written in C, that allows you to execute basic shell commands and navigate through directories. The project is compatible with Linux and macOS operating systems.

## Requirements

* gcc (GNU Compiler Collection)

## How to use

1. Clone the repository to your local machine

```
$ git clone https://github.com/Nicholas2023/simple_shell
```

2. Open the terminal and navigate to the project directory

```
$ cd simple_shell
```

3. Compile the shell script

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

4. Run the shell script

```
./hsh
```

5. The shell prompt will appear, and you can start executing commands

```
$ ls
$ pwd
$ cd <directory>
$ touch <file_name>
$ echo <text>
$ cat <file_name>
$ rm <file_name>
$ rmdir <directory_name>
$ exit
```

## Features

* Execute basic shell commands
* Allows navigation through directories
* Supports creation and deletion of directories and files
* Displays the current working directory
* Can display the contents of a file
* Can display a custom message on the console using the echo command

## Known issues

* The shell does not support wildcard characters (*, ?, etc)
* The shell does not support piping or input/output redirection

## License

This project is licensed under the MIT license. See the [LICENSE] file for details

Authors: `Nicholas Otieno` and `Anna Wambui`
