/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:46 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/10 16:26:20 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_num_words(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		words++;
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (words);
}

char	*get_word(char *str, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	len = i;
	word = malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		words;
	char	**array;

	i = 0;
	words = get_num_words(str, c);
	array = 0;
	array = malloc(sizeof(char *) * words + 1);
	if (!array)
		return (NULL);
	while (*str && *str == c)
		str++;
	while (*str)
	{
		array[i] = get_word(str, c);
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
		i++;
	}
	array[i] = (char *) NULL;
	return (array);
}
