

#include "minishell.h"

void	ft_history_init_fd(char *file, int *fd)
{
	int	t;

	(void)t;
	(*fd) = open(file, O_RDONLY | O_RDWR | O_APPEND);
	if (*fd == -1)
	{
		t = unlink(file);
		(*fd) = open(file, O_RDONLY | O_RDWR | O_CREAT, 0644);
	}
}

void	write_first_c(char *buffer, char *str)
{
	buffer[0] = '\0';
	str[0] = '\0';
}

void	ft_init_commands_history(t_m *var)
{
	char *str;

	str = readline("minishell>");
	if (str)
	{
		ft_history_init_fd(".history", &(*var).h_fd);
		write((*var).h_fd, str, ft_strlen(str));
		// (*var).args_line = str;
		(*var).args_line = ft_strdup(str);
		free(str);
	}
}

void	ft_print_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printf("SPLIT[%d]=%s]\n", i, str[i]);
		i++;
	}
	ft_printf("-----------------\n");
}

void handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int argc, char **argv, char **envp)
{
	t_m	var;
	char ***args;

	signal(SIGINT, handle_sigint); /* ctrl + c  affiche un nouveau prompt */
	signal(SIGQUIT, SIG_IGN); /* ctrl + \  ne fait rien */
	(void)argv;
	(void)envp;
	if (argc != 1)
		return (ft_printf("Error : Wrong Number of arguments\n"), 1);
	if (ft_env(&var, envp) == -1)
		return (ft_printf("Error : Malloc for keep env fail\n"), 1);
	if(!*envp)
		write(2, "EXIT PATH\n", 11);
	ft_init_commands_history(&var);
	ft_printf("Command is :%s\n", var.args_line);
	args = ft_parsing(var.args_line, envp);
	ft_puttripletab(args);
	free_tripletab(args);
	free(var.args_line);
	ft_free_split(var.env);
	return (0);
}
