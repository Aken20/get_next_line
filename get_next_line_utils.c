/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:00:19 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/11/22 11:50:41 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s, int k)
{
	size_t	i;
	size_t	n;
	char	*dup;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (0);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[n] = '\0';
	if (k == 1)
		free(s);
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l;
	size_t	l1;
	char	*sjn;

	if (!s1 && !s2)
		return (ft_strdup("", 0));
	if (!s2)
		return (ft_strdup(s1, 1));
	if (!s1)
		return (ft_strdup(s2, 0));
	l = ft_strlen(s1);
	l1 = ft_strlen(s2);
	sjn = (char *) malloc((l + l1) + 1);
	if (!sjn)
		return (0);
	l = -1;
	while (s1[++l])
		sjn[l] = s1[l];
	l1 = 0;
	while (s2[l1])
		sjn[l++] = s2[l1++];
	sjn[l] = 0;
	return (free(s1), sjn);
}

char	*ft_strchr(char *s, int c)
{
	char	*c_s;

	while (*s)
	{
		if (*s != (char)c)
			++s;
		else
		{
			c_s = (char *) s;
			return (c_s);
		}
	}
	if (*s == (char)c)
	{
		c_s = (char *) s;
		return (c_s);
	}
	return (NULL);
}
