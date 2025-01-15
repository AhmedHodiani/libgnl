# libgnl

`libgnl` is a custom implementation of the C standard library function `getline`. It allows you to read and parse a text file line by line, regardless of the line length.

## Usage

To use `libgnl`, include the header file in your program:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libgnl.h"

int main()
{
	int fd = open("file.txt", O_READONLY);

	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}

	close(fd);
}
```
