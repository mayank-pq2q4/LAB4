<h3 align="center">LAB ASSIGNMENT 4</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/mayank-pq2q4/LAB4.svg)](https://github.com/mayank-pq2q4/LAB4/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/mayank-pq2q4/LAB4.svg)](https://github.com/mayank-pq2q4/LAB4/pulls)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)

</div>

---

<p align="center"> Trying to mimic a shell program.
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Built Using](#built_using)
- [TODO](../TODO.md)
- [Contributing](../CONTRIBUTING.md)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

Extend the program written for Lab task 2 to read multiple file names from the command prompt and to be able to read interactively from the user.
Each file contains a  list of commands, one per each line, with variable number of arguments. Write a C program to read each command and its arguments and execute them. Once the program doesn't have any more lines to read from a file, it will process the next file and so on. For this lab, you may assume that no files have overlapping commands. Once there are no more files to read, the program will move to an interactive mode and start reading user inputs. You are to implement the following two features.  In the interactive mode, the program should prompt user for inputs as follows:

"Please enter your command:"

The following commands should be supported.

1.  When the user types command "HISTORY BRIEF", the program should list out all the commands (no need for file names) that were executed so far without the respective arguments. The display should show one command per line.

2. When the user types command "HISTORY FULL", the program should list all the commands so far with their respective arguments. Each command should have an INDEX number associated with it and it should be displayed as well.

3. If the user types "EXEC <COMMAND_NAME>", your program should execute that command with its arguments.

4. When  If the user types "EXEC <COMMAND_INDEX_NUMBER>", your program should execute that command with its arguments.

5. The program should exit when the user types a special command "STOP".

6. The program should handle following border conditions:
a. At least one file name should be supplied when the program starts.
b. For unrecognized commands (not in history), the program should type appropriate message.
c. Avoid memory leaks and segmentation faults. Don't allocate memory where not required and as far as possible free memory.


## 🏁 Getting Started <a name = "getting_started"></a>

Download as zip. Then unzip. Then,
- To compile: `make`. 
- To run: `./shl`, 
- To check for memory leaks (runs it with valgrind): `make leaks`


### Prerequisites

Make sure you have valgrind installed for memory debugging or memory leaks detection, or `make leaks` wont work.

```
sudo apt-get install valgrind
```


## 🎈 Usage <a name="usage"></a>

Type `compgen` or `HISTORY BRIEF` to see the list of commands it can perform.

## ⛏️ Built Using <a name = "built_using"></a>

- [C](http://www.open-std.org/jtc1/sc22/wg14/) - C Language
- [Valgrind](https://valgrind.org/) - Valgrind instrumentation framework

## ✍️ Authors <a name = "authors"></a>

- [@mayank-pq2q4](https://github.com/mayank-pq2q4)

See also the list of [contributors](https://github.com/mayank-pq2q4/LAB4/graphs/contributors) who participated in this project.
## The code will be merged after wed: 1800 hours
