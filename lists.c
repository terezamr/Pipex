/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:37:07 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/10 16:53:29 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{	
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	initialize_lst(t_list **new)
{
	(*new)->command = 0;
	(*new)->param = 0;
	(*new)->path = 0;
	(*new)->inputf = 0;
	(*new)->outputf = 0;
	(*new)->next = 0;
}

t_list	*ft_lstnew(char **str, char **paths, int i, int com)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	initialize_lst(&new);
	new->param = ft_split(str[i + 2], ' ');
	new->command = new->param[0];
	new->path = check_path(paths, new->command);
	if (i == 0)
	{
		if (str[1][0] != 47 && str[1][0] != '.')
			new->inputf = ft_strjoin("./", str[1]);
		else
			new->inputf = ft_strjoin("", str[1]);
	}
	if (i == com - 1)
	{
		if (str[i + 3][0] != 47 && str[i + 3][0] != '.')
			new->outputf = ft_strjoin("./", str[i + 3]);
		else
			new->outputf = ft_strjoin("", str[i + 3]);
	}
	return (new);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*aux;

	if (!new)
		return ;
	else if (!lst)
		lst = new;
	else
	{
		aux = ft_lstlast(lst);
		aux->next = new;
	}
}

t_list	*create_list(char **argv, int commands, t_list *lst, char **paths)
{
	t_list	*aux;

	lst = ft_lstnew(argv, paths, 0, commands);
	aux = ft_lstnew(argv, paths, 1, commands);
	ft_lstadd_back(lst, aux);
	return (lst);
}

t_list	*create_list_bonus(char **argv, int commands, t_list *lst, char **paths)
{
	t_list	*aux;
	int		i;

	i = 0;
	aux = NULL;
	lst = ft_lstnew(argv, paths, i, commands);
	i++;
	while (i < commands)
	{
		aux = ft_lstnew(argv, paths, i, commands);
		ft_lstadd_back(lst, aux);
		i++;
	}
	return (lst);
}