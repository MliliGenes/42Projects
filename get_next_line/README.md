# Get Next Line

`get_next_line` is a project from 42 school that requires us to create a function that reads a file line by line. This project is a great way to learn about static variables, file descriptors, and memory management in C.

## Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters

- `fd`: The file descriptor to read from.

### Return Value

- The line that was read.
- `NULL` if there is nothing else to read, or if an error occurred.

## How to Use

1. **Compile the files:** Compile the `get_next_line.c` and `get_next_line_utils.c` files along with your project.
2. **Include the header:** Include the `get_next_line.h` header file in your C project.
3. **Call the function:** Call the `get_next_line` function with a file descriptor as an argument.

## Bonus

The bonus part of this project involves handling multiple file descriptors at the same time. This is achieved by using an array of static variables to store the buffer for each file descriptor.

## Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
