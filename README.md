# C exercise: debugging
A small exercice made to train with debugging tools.

The `resources` folder contains a file named `main.c`.
This file presents a lot of compile errors, runtime errors
as well as general coding mistakes (bad variable names,
no errors handling, missing fclose and free calls, etc).

The goal is to fix all those issues with different tools.

You should compile the code with the following line:
`gcc -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address -g main.c`
