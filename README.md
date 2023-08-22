this repo contains files for programming a simple shell.

the project process came about mainly solving each exercise in the cocept page: https://intranet.alxswe.com/concepts/64

I made a separate/private repo solely for those tasks; which naturally made the shell programming easier to get


update made frequently...
PROBLRMS:
----handeling errors----
----exit-args----------- <<---- S  O  L  V  E  D??
---- ||   && -----------
---- echo $$ + $?(after exiting hsh) ------ <<--- S  O  L  V  E  D
++ own getline+strtok <<---- S  O  L  V  E  D

       errors now: (COMMAND_name): No such file or directory
       the goal  : ./shell: No such file or directory
---- Output
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0]  -----


the two main file are: shell_repl.c <-- the shell interactive mode

batch_mode <-- the shell non_interactive mode

exit + char : exits the shell, it used to show an error demanding to enter an integer only.

for setenv/unsetenv: the echo $var_name doesn't work <<--- SOLVED
