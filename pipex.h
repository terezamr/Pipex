/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:08:27 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/10 13:08:27 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h> 
# include <sys/wait.h>

typedef struct s_list
{
	char			*command;
	char			**param;
	char			*path;
	char			*inputf;
	char			*outputf;
	struct s_list	*next;
}					t_list;

void	command(int *fd, t_list *lst, char **envp, int i);
void	pipex(t_list *lst, char **envp);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little);

char	**ft_split(char *str, char c);

void	ft_strn(char *str);
void	error(int status);
char	**get_paths(char **envp);
void	free_double(char **path1);
void	free_path(char **right_path);

char	*check_path(char **paths, char *command);

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char **str, char **paths, int i, int commands);
void	ft_lstadd_back(t_list *lst, t_list *new);
t_list	*create_list(char **argv, int commands, t_list *lst, char **paths);
void	free_lst(t_list *lst);

#endif