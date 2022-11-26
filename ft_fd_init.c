/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:18 by chillion          #+#    #+#             */
/*   Updated: 2022/11/26 18:08:54 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_fd(char *file, int *fd, int *fake_fd)
{
	int	t;

	(*fake_fd) = 0;
	(void)t;
	(*fd) = open(file, O_RDONLY | O_RDWR);
	if (*fd == -1)
	{
		(*fake_fd) = -1;
		ft_printf("%s: ", file);
		perror("");
	}
}

void	ft_create_init_fd(char *file, int *fd, int *fake_fd2)
{
	int	t;

	(*fake_fd2) = 0;
	(void)t;
	if (ft_check_fd_status(file, fd) == 1)
	{
		t = unlink(".tmp_fakefd2");
		(*fd) = open(".tmp_fakefd2", O_RDONLY | O_RDWR | O_CREAT, 0644);
		t = unlink(".tmp_fakefd2");
		(*fake_fd2) = -1;
	}
	else
	{
		t = unlink(file);
		(*fd) = open(file, O_RDONLY | O_RDWR | O_CREAT, 0644);
	}
	if (*fd == -1)
	{
		ft_printf("Error\n%s", strerror(EBADF));
		exit(EXIT_FAILURE);
	}
}

void	ft_heredoc_init_fd(char *file, int *fd, int *fake_fd2)
{
	int	t;

	(void)t;
	(*fake_fd2) = 0;
	if (ft_check_fd_status(file, fd) == 1)
	{
		t = unlink(".tmp_fakefd2");
		(*fd) = open(".tmp_fakefd2", O_RDONLY | O_RDWR | O_CREAT, 0644);
		t = unlink(".tmp_fakefd2");
		(*fake_fd2) = -1;
	}
	else
	{
		(*fd) = open(file, O_RDONLY | O_RDWR | O_APPEND);
		if (*fd == -1)
		{
			t = unlink(file);
			(*fd) = open(file, O_RDONLY | O_RDWR | O_CREAT, 0644);
			if (*fd == -1)
			{
				ft_printf("Error\n%s", strerror(EBADF));
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	ft_tmpheredoc_init_fd(char *file, int *fd)
{
	int	t;

	(void)t;
	t = unlink(file);
	(*fd) = open(file, O_RDONLY | O_RDWR | O_CREAT, 0644);
	if (*fd == -1)
	{
		ft_printf("Error\n%s", strerror(EBADF));
		exit(EXIT_FAILURE);
	}
}

void	ft_init_fake_fd(char *file, int *fd)
{
	int	t;

	(void)t;
	(*fd) = open(file, O_RDONLY | O_RDWR | O_CREAT, 0644);
	t = unlink(file);
	if (*fd == -1)
	{
		ft_printf("Error\n%s", strerror(EBADF));
		exit(EXIT_FAILURE);
	}
}
