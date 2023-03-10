/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:34:14 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/10 15:34:14 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

t_list	*get_node(t_list *lst, int i);
void	do_dups(int fin, int fout, int fd_close);
void	command_bonus(int **fd, t_list *lst, int i, char **envp);
int		**create_pipes(int com);
void	pipex_bonus(t_list *lst, int com, char **envp);

char	*check_path(char **paths, char *command);
char	**get_paths(char **envp);

void	ft_strn(char *str);
void	error(int status);
void	free_double(char **path1);
void	free_lst(t_list *lst);

int		get_num_words(char *str, char c);
char	*get_word(char *str, char c);
char	**ft_split(char *str, char c);

t_list	*ft_lstlast(t_list *lst);
void	initialize_lst(t_list **new);
t_list	*ft_lstnew(char **str, char **paths, int i, int com);
void	ft_lstadd_back(t_list *lst, t_list *new);
t_list	*create_list_bonus(char **argv, int commands, t_list *lst, char **paths);

#endif