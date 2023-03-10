/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:05:04 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/10 16:18:18 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char **paths, char *command)
{
	int		i;
	char	*path1;
	char	*path2;

	i = 0;
	while (paths[i])
	{
		path1 = ft_strjoin(paths[i], "/");
		path2 = ft_strjoin(path1, command);
		free(path1);
		if (access(path2, X_OK) == 0)
			return (path2);
		free(path2);
		i++;
	}
	return (NULL);
}

char	**get_paths(char **envp)
{
	int		i;
	char	**paths;
	char	*aux;

	i = 0;
	paths = 0;
	while (envp[i])
	{
		aux = ft_strnstr(envp[i], "PATH");
		if (aux)
			paths = ft_split(aux, ':');
		i++;
	}
	return (paths);
}
