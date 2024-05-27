# Minishell: Unleash the Power of Shell Scripting in Your Own Custom Shell!

|    Project Name    |                                                                       minishell                                                                      |
| :----------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------: |
|    Description     |                                             An implementation of C-based shell capable of handling redirections, pipes, environment variables, and various built-in functionalities.                                             |
|    Technologies    | <a href="#"><img alt="C" src="https://custom-icon-badges.demolab.com/badge/C-03599C.svg?logo=c-in-hexagon&logoColor=white&style=for-the-badge"></a> |
| External libraries |     readline(), rl_clear_history(), rl_on_new_line(), rl_replace_line(), rl_redisplay(), add_history(), printf(), malloc(), free(), write(), access(), open(), read(), close(), fork(), wait(), waitpid(), wait3(), wait4(), signal(), sigaction(), sigemptyset(), sigaddset(), kill(), exit(), getcwd(), chdir(), stat(), lstat(), fstat(), unlink(), execve(), dup(), dup2(), pipe(), opendir(), readdir(), closedir(), strerror(), perror(), isatty(), ttyname(), ttyslot(), ioctl(), getenv(), tcsetattr(), tcgetattr(), tgetent(), tgetflag(), tgetnum(), tgetstr(), tgoto(), tputs()      |

##### Usage

```bash
  gcl https://github.com/trobert42/minishell.git
  cd minishell
  make
  ./minishell
```


## Project Overview:

### Summary:

Minishell offers you the opportunity to delve into the fascinating world of shell scripting by creating your own miniature version of a shell. Dive deep into processes, file descriptors, and command interpretation to build a functional and efficient shell from scratch.

### Key Features:

1. Parsing Complexity: Experience the challenge of parsing user commands, handling quotes, special characters, and redirections with precision and accuracy. Navigate through the intricacies of command interpretation to ensure seamless execution.
2. Built-in Commands: Implement essential built-in commands such as echo, cd, pwd, export, unset, env, and exit to provide core functionality within the shell environment. Ensure robust error handling and compatibility with standard shell behavior.
3. Fork and Pipes: Harness the power of process forking and inter-process communication using pipes (|) to enable command chaining and execution. Manage the flow of data between commands efficiently to maintain the integrity of the shell.
4. Redirection and Heredoc: Support various redirection operators (<, >, >>) to manipulate input and output streams, allowing users to redirect data to and from files seamlessly. Implement heredoc functionality (<<) to facilitate interactive input without altering command history.


### Things to Do:

1. Command Parsing: Develop a robust command parser capable of handling quotes, special characters, and redirections according to shell syntax standards. Ensure accurate interpretation of user commands to maintain shell integrity.
2. Built-in Command Implementation: Implement essential built-in commands with proper error handling and behavior consistent with standard shell utilities. Ensure compatibility with common shell functionalities for a seamless user experience.
3. Fork and Pipe Management: Utilize process forking and pipes to execute commands in separate processes and facilitate data communication between them. Handle process synchronization and resource management efficiently to avoid deadlock and resource leakage.
4. Redirection and Heredoc Handling: Support various redirection operators and heredoc functionality to enable flexible input/output manipulation for users. Ensure proper handling of file descriptors and data streams to prevent data corruption and loss.
5. Error Handling and Testing: Implement comprehensive error handling mechanisms to detect and handle runtime errors gracefully. Develop test cases to verify the correctness and robustness of your shell implementation under various scenarios.

Embark on your journey to mastering shell scripting with Minishell, where you'll explore the intricacies of command interpretation, process management, and data manipulation in a custom shell environment.
