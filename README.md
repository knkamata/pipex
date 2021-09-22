## Overview
`pipex`, an emulation program of  `<`, `|`, `>`, `heredoc`, `<<`, and `>>` in CLI, executes shell commands passed as arguments and redirects the result to the other file.

## Usages
`git clone` the repository and execute the `make` command inside the cloned directory.

```shell
$ ./pipex <file1> <cmd1> <cmd2> ... <cmdn> <file2>
# Works as $ < <file1> <cmd1> | <cmd2> > file2

$ ./pipex here_doc <LIMITER> <cmd1> <cmd2> <file>
# Works as $ <cmd1> << <LIMITER> | <cmd2> >> <file>
```

## Examples
```shell
./pipex infile "grep foo" "wc -l" outfile
./pipex infile cat cat cat cat cat outfile
./pipex here_doc END "grep foo" "wc -l" outfile
```

## Description
- Allowed as many commands as you want between the input/output files
- Allowed for commands specified by the path
- Avoided pipe blocking in concurrency
- Set exit status `1` for a general error and `127` for not command found
- Set close-on-flag to opened file descriptors
