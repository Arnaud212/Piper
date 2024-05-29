# Pipex

## Description
Pipex is a C project designed to replicate the behavior of a shell command using pipes. The program takes four arguments: two files and two commands, and redirects the streams between these elements in the same way as the shell command `< file1 cmd1 | cmd2 > file2`.

## Compilation
To compile the project, use the provided Makefile:
```sh
make
```

## Usage
Run the program with the following syntax:
```sh
./pipex file1 "cmd1" "cmd2" file2
```
### Example

```sh
./pipex infile "ls -l" "wc -l" outfile
```

Which is equivalent to:

```sh
< infile ls -l | wc -l > outfile
```