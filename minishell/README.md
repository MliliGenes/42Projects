# Minishell

Minishell is a project from 42 school that requires us to create a simple shell, a command-line interpreter that can execute programs and manage processes. This project is a great way to learn about process management, file descriptors, and parsing in C.

## Features

My implementation of `minishell` supports the following features:

- **Command Execution:** Execute simple commands with arguments.
- **Built-in Commands:**
    - `echo`: with the `-n` option.
    - `cd`: with relative or absolute paths.
    - `pwd`: with no options.
    - `export`: with no options.
    - `unset`: with no options.
    - `env`: with no options or arguments.
    - `exit`: with no options.
- **Redirections:**
    - `<`: Redirect input.
    - `>`: Redirect output.
    - `<<`: Here document.
    - `>>`: Append output.
- **Pipes:** `|` operator to chain commands.
- **Environment Variables:** Handle environment variables (`$VAR`).
- **Signals:** Handle `Ctrl-C`, `Ctrl-D`, and `Ctrl-\`.

## Bonus Features

The bonus part of this project includes support for:

- **Logical Operators:** `&&` and `||` for conditional execution.
- **Wildcards:** `*` for filename expansion.

## How to Use

1. **Compile the project:** Run `make` to compile the project.
2. **Run the shell:** Execute the `minishell` binary.
3. **Enter commands:** Type commands and press Enter.

## Project Structure

The project is divided into several main components:

- **Tokenizer:** Breaks the input string into a sequence of tokens.
- **Parser:** Builds an abstract syntax tree (AST) from the token sequence.
- **Executor:** Traverses the AST and executes the commands.
- **Built-ins:** Implements the shell's built-in commands.
- **Signals:** Handles signals to ensure the shell is responsive.
- **Expansion:** Handles environment variable and wildcard expansion.
