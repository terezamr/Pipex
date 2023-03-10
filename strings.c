/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:53:19 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/10 15:29:40 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len = len + 1;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		a;
	int		b;

	a = 0;
	b = 0;
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr || !s1 || !s2)
		return (0);
	while (s1[a] != '\0')
	{
		ptr[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		ptr[a] = s2[b];
		a++;
		b++;
	}
	ptr[a] = '\0';
	return (ptr);
}

char	*ft_strnstr(const char *big, const char *little)
{
	size_t	count;
	size_t	a;

	count = 0;
	if (!little[0] || !little)
		return ((char *)big);
	while (little && count < ft_strlen(big))
	{
		a = 0;
		while (big[count + a] == little[a] && big)
		{
			a++;
			if (little[a] == '\0' && big[count + a] == '='
				&& big[0] == little[0])
				return ((char *)big + count + ft_strlen(little) + 1);
		}
		count++;
	}
	return (NULL);
}
