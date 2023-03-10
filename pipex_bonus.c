/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:22:29 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/10 15:54:10 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_list	*get_node(t_list *lst, int i)
{
	int		f;
	t_list	*node;

	f = 0;
	node = lst;
	while (f < i)
	{
		node = node->next;
		f++;
	}
	return (node);
}

void	command_bonus(int **fd, t_list *lst, int i, char **envp)
{
	t_list	*node;
	int		f_in;
	int		f_out;

	if (i == 0)
		node = lst;
	else
		node = get_node(lst, i);
	if (node->inputf)
	{
		close(fd[i][0]);
		f_in = open(node->inputf, O_RDONLY, 0444);
		if (f_in == -1)
			error(1);
		dup2(f_in, STDIN_FILENO);
		dup2(fd[i][1], STDOUT_FILENO);
		close(f_in);
	}
	else if (node->outputf)
	{
		close(fd[i - 1][1]);
		f_out = open(node->outputf, O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (f_out == -1)
			error(1);
		dup2(fd[i - 1][0], STDIN_FILENO);
		close(fd[i - 1][0]);
		dup2(f_out, STDOUT_FILENO);
		close (f_out);
	}
	else
	{
		close(fd[i][0]);
		close(fd[i - 1][1]);
		dup2(fd[i - 1][0], STDIN_FILENO);
		dup2(fd[i][1], STDOUT_FILENO);
	}
	execve(node->path, node->param, envp);
	perror("pipex");
}

int	**create_pipes(int com)
{
	int	i;
	int	f;
	int	**id;

	i = 0;
	f = 3;
	id = 0;
	id = malloc(sizeof(int *) * (com - 1));
	if (!id)
		exit(0);
	while (i < com - 1)
	{
		id[i] = malloc(sizeof(int) * 2);
		id[i][0] = f;
		id[i][1] = f + 1;
		f = f + 2;
		i++;
	}
	return (id);
}

void	pipex_bonus(t_list *lst, int com, char **envp)
{
	int	i;
	int	f;
	int	**id;
	int	*pa;

	i = 0;
	f = 3;
	pa = malloc(sizeof(int) * com);
	if (!pa)
		return ;
	id = create_pipes(com);
	while (i < com)
	{
		if (i != com - 1)
			pipe(id[i]);
		pa[i] = fork();
		if (pa[i] == -1)
			error(1);
		else if (pa[i] == 0)
			command_bonus(id, lst, i, envp);
		if (i != com - 1)
			close(id[i][1]);
		i++;
	}
	waitpid(-1, 0, 0);
	free(pa);
	i = 0;
	while (i < com - 1)
	{
		free(id[i]);
		i++;
	}
	free(id);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		command_number;
	t_list	*lst;
	int		i;

	i = 0;
	if (argc < 5)
		error(1);
	lst = 0;
	command_number = argc - 3;
	paths = get_paths(envp);
	lst = create_list_bonus(argv, command_number, lst, paths);
	pipex_bonus(lst, command_number, envp);
	free(paths);
	free_lst(lst);
	return (0);
}
