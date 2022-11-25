/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:07:52 by chillion          #+#    #+#             */
/*   Updated: 2022/11/24 16:36:27 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exportunset_with_arg(t_m *var, char **args, int soft)
{
	int	egalen;

	egalen = 0;
	if (soft == 1)
	{
		while (*args)
		{
			if (ft_export_check_args(*args, &egalen))
				ft_export_check_double(var, *args, egalen);
			args++;
		}
	}
	if (soft == 2)
	{
		while (*args)
		{
			if (ft_unset_check_args(*args, &egalen))
				ft_unset_check_double(var, *args, egalen);
			args++;
		}
	}
}

void	ft_export_check_double(t_m *var, char *args, int egalen)
{
	int		i;
	char	*tmp;

	i = 0;
	while((*var).env[i])
	{
		if (!ft_strncmp((*var).env[i], args, (egalen + 1)))
		{
			free((*var).env[i]);
			tmp = ft_strdup(args);
			(*var).env[i] = tmp;
			return ;
		}
		i++;
	}
	ft_export_add(var, args);
}

void	ft_export_add(t_m *var, char *args)
{
	int	i;
	char **tmp;

	i = ft_tablen((*var).env);
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	if (!tmp)
		return (printf("malloc error\n"), exit(1));
	tmp[i + 1] = 0;
	i = 0;
	while ((*var).env[i])
	{
		tmp[i] = (*var).env[i];
		i++;
	}
	tmp[i] = ft_strdup(args);
	free((*var).env);
	(*var).env = tmp;
}

int	ft_export_check_args(char *args, int *egalen)
{
	if (!args && !*args)
		return (0);
	if ((ft_isalpha(args[0]) == 0) && args[0] != '_')
		return (printf("export: `%s': not a valid identifier\n", args), 0);
	*egalen = -1;
	while ((++*egalen) > -1 && args[(*egalen)] && args[(*egalen) + 1] != '=')
	{
		if (args[*egalen] != '_' && (ft_isalnum(args[*egalen]) == 0))
			return (printf("export: `%s': not a valid identifier\n", args), 0);
	}
	if (args[*egalen] == '\0')
		return (0);
	return ((++*egalen));
}
