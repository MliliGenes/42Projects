# libft

`libft` is a project from 42 school that requires us to re-implement a set of standard C library functions, as well as some additional utility functions. This project is a great way to understand the inner workings of these functions and to build a personal library that can be used in future projects.

## Functions

The library is divided into several parts:

### Part 1: Libc Functions

These are re-implementations of standard C library functions.

- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
- `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`
- `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`
- `ft_atoi`, `ft_calloc`, `ft_strdup`

### Part 2: Additional Functions

These are utility functions that are not part of the standard C library.

- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`
- `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`
- `ft_putendl_fd`, `ft_putnbr_fd`

### Part 3: Bonus Functions

These are functions for working with linked lists.

- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`
- `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## How to Use

1. **Compile the library:** Run `make` to compile the project and create a static library `libft.a`.
2. **Include the header:** Include the `libft.h` header file in your C project.
3. **Link the library:** When compiling your project, link it with the `libft.a` library.
