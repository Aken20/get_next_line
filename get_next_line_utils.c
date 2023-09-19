/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:00:19 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/19 05:11:31 by ahibrahi         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	n;
	char	*dup;

	n = 0;
	while (s[n])
		n++;
	if (s == 0)
		return (NULL);
	dup = (char *) malloc(n + 1);
	if (dup == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	size_t	l1;
	size_t	len;
	char	*sjn;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	l = ft_strlen(s1);
	l1 = ft_strlen(s2);
	len = (l + l1);
	sjn = (char *) malloc(len + 1);
	if (!sjn)
		return (0);
	l = -1;
	while (s1[++l])
		sjn[l] = s1[l];
	l1 = 0;
	while (s2[l1])
		sjn[l++] = s2[l1++];
	sjn[l] = 0;
	return (sjn);
}

char	*ft_strchr(const char *s, int c)
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