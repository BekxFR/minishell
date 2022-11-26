/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_args_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:59:05 by chillion          #+#    #+#             */
/*   Updated: 2022/11/26 18:27:00 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_init_path_var(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' \
		&& envp[i][2] == 'T' && envp[i][3] == 'H' \
		&& envp[i][4] == '=' && envp[i][5])
			return ((envp[i] + 5));
		i++;
	}
	return (NULL);
}

void	ft_free_split_exclude_line(char **str, int line)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == line)
			i++;
		else
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
}

int	ft_check_fd_status(char *file, int *fd)
{
	*fd = open(file, O_RDONLY | O_RDWR);
	if (*fd == -1 && ((errno == EACCES) || (errno == EISDIR)))
	{
		ft_putstr_fd(file, 2);
		perror(" ");
		return (1);
	}
	if (*fd != -1)
		close (*fd);
	return (0);
}

void	ft_cleanheredoc_fd(char *str, char *buffer, char *comp, int fd1)
{
	free(str);
	free(buffer);
	free(comp);
	close(fd1);
}