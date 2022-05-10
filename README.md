# pipex

## Description

The purpose of this project is to simulate the UNIX pipe. It gives a deeper understanding of multiple processes, file descriptors, exec commands and handling errors.    
The files have to compile with -Wall -Werror -Wextra and to be free of memory leaks. The written code must follow certain rules, which are specified in a standard of the school 42.

### Allowed functions

```
open, close, read, write, malloc, free, 
perror, strerror, access, dup, dup2,
execve, exit, fork, pipe, unlink, wait, waitpid
```
```
self coded ft_printf
```


## Mandatory Part

The pipex program is to be executed in this way:

```
./pipex file1 cmd1 cmd2 file2
```

Which should be similar to the shell command:
```
< file1 cmd1 | cmd2 > file2
```

Errors must be handled in the same way as in the shell.


## Bonus Part

* ### Multiple pipes must be handled.
```
./pipex file1 cmd1 cmd2 cmd3 cmd4 ... file2
```
* ### Here_doc implementation   

The programm must be able to read form the terminal.   
Should be executed like this:
```
./pipex here_doc LIMITER cmd1 cmd2 file
```

And should behave similarly to the shell command:

```
cmd << LIMITER | cmd1 >> file
```


## Skills

* Unix
* Imperative programming


## Getting Started

### Clone the repository
```shell
git clone git@github.com:wolumen/pipex.git
cd pipex
```

### Compiling

The Makefile has the following rules:

| Rule | Function |
| - | - |
| ``make`` | Compiles pipex executable. |
| ``make clean`` | Deletes all object files. |
| ``make fclean`` | Deletes the object files and the executable. |
| ``make re`` | Makes ``fclean`` and ``make`` again. |
| ``make bonus`` | Compiles with the bonus files. |
| ``make test[1-3]`` | Doeas ``make`` and runs the program with provided arguments and infile. An outfile will be created. |
| ``make memcheck`` | Runs the program with Valgrind and provided arguments. A logfile will be created. |
