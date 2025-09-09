# Pipex

`pipex` is a project from 42 school that requires us to simulate the behavior of the shell's pipe (`|`) operator. This project is a great way to learn about process creation, file descriptors, and inter-process communication in C.

## Program Behavior

The `pipex` program takes four arguments:

1. `infile`: The name of the input file.
2. `cmd1`: The first command to execute.
3. `cmd2`: The second command to execute.
4. `outfile`: The name of the output file.

It should behave like the following shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

## Bonus Features

The bonus part of this project includes support for:

- **Multiple Pipes:** Handle an arbitrary number of commands chained with pipes.
- **Here Documents:** Support for `<<` redirection.

The bonus version should behave like the following shell command:

```bash
< infile cmd1 | cmd2 | ... | cmdn > outfile
```

or with a here document:

```bash
cmd1 << 'LIMITER' | cmd2 > outfile
```

## How to Run

1. **Compile the project:** Run `make` to compile the mandatory part or `make bonus` for the bonus part.
2. **Run the program:** Execute the `pipex` binary with the required arguments.

### Example

```bash
# Behaves like: < infile ls -l | wc -l > outfile
./pipex infile "ls -l" "wc -l" outfile
```
