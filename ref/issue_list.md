# Errors

This files lists most errors I willingly put into the code.
the goal is to ask students what is wrong in the code and
try to guide them into fixing these mistakes.


# Files

## main.c

- Missing stdlib include

- Main definition: wrong type for argv - should be `char *argv[]`

- Main: error logs are written on stdout

- First fopen: the opened file is named a, the first parameter should be
  argv[1], the mode should be "r" as we only need to read the file. No error
  handling if fopen fails.

- Variable `line` defined without initialization - should be `char *line = NULL`

- `line` is allocated by getline and never freed

- Wrong use of line in getline call: we should take its address instead of dereferencing it

- `abcd` bad variable name

- `if (abcd == -1)`: return 1 is not part of the body

- `new = malloc(...)`: wrong size

- `new->prev`: should be initialized with current instead of head

- The second `strtok_r` call should pass NULL and &save as first and third arguments

- `size` should be incremented at the end of the loop

- `while(head->next)`: the loop should operate on `current`

- Missing fclose call at the end

- Use after free in the list free loop: it frees only the first element

- Once the loop is fixed, the last element can still leak because we stop the
  loop as soon as `head->next` is null thus forgetting to free the last element.
