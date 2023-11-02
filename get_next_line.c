/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:00:12 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/11/02 13:09:09 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static	char	*set_tmp(char *str)
// {
// 	int		i;
// 	int		c;
// 	char	*tmp;

// 	i = 0;
// 	while (str[i] && str[i] != '\n')
// 		i++;
// 	c = ft_strlen(str) - i;
// 	tmp = (char *)malloc(sizeof (char) * (c + 1));
// 	c = 0;
// 	while (str[i])
// 	{
// 		tmp[c] = str[i];
// 		i++;
// 		c++;
// 	}
// 	return (tmp);
// }

// static	char	*first_line(char *str)
// {
// 	int		i;
// 	char	*nstr;

// 	i = 0;
// 	while (str[i] && str[i] != '\n')
// 		i++;
// 	nstr = (char *)malloc(sizeof (char) * (i + 1));
// 	if (!nstr)
// 		return (0);
// 	i = 0;
// 	while (str[i] && str[i] != '\n')
// 	{
// 		nstr[i] = str[i];
// 		i++;
// 	}
// 	if (str[i] == '\n')
// 		nstr[i++] = '\n';
// 	nstr[i] = 0;
// 	return (nstr);
// }

// static	char	*rem_line(char *tmp)
// {
// 	int		i;
// 	int		c;
// 	char	*ntmp;

// 	i = 1;
// 	c = 0;
// 	while (tmp[i] != '\n')
// 		i++;
// 	ntmp = ft_strdup(tmp + i);
// 	return (ntmp);
// }

// static	char	*set_line(char *tmp)
// {
// 	char	*str;
// 	int		c;
// 	int		i;

// 	c = 0;
// 	i = 0;
// 	while (tmp[i] && tmp[i] != '\n')
// 		i++;
// 	str = (char *)malloc(sizeof (char) * (i + 1));
// 	if (tmp[c] && tmp[c] == '\n')
// 	{
// 		c++;
// 		i = 0;
// 		while (tmp[c] && tmp[c] != '\n')
// 			str[i++] = tmp[c++];
// 		str[i] = 0;
// 		return (str);
// 	}
// 	return (0);
// }

// char	*get_next_line(int fd)
// {
// 	char			*buf;
// 	char			*str;
// 	static char		*tmp;
// 	int				i;

// 	i = 1;
// 	if (!fd)
// 		return (0);
// 	if (tmp)
// 	{
// 		// while (tmp[i] && tmp[i] != '\n')
// 		// 	i++;
// 		str = set_line(tmp);
// 		tmp = rem_line(tmp);
// 		return (str);
// 	}
// 	buf = (char *)malloc(BUFFER_SIZE + 1);
// 	if (!buf)
// 		return (0);
// 	str = (char *)malloc(BUFFER_SIZE + 1);
// 	if (!str)
// 		return (0);
// 	while ((read(fd, buf, BUFFER_SIZE)))
// 	{
// 		buf[BUFFER_SIZE + 1] = 0;
// 		str = ft_strjoin(str, buf);
// 		if (ft_strchr(str, '\n'))
// 		{
// 			tmp = set_tmp(str);
// 			free(buf);
// 			str = first_line(str);
// 			return (str);
// 		}
// 		ft_bzero(buf);
// 	}
// 	free(buf);
// 	return (str);
// }

char	*get_next_line(int fd)
{
	
}


int	main(void)
{
	char	*s;
	int		fd;

	fd = open("./test.txt", O_RDONLY);
	printf("%s-", get_next_line(fd));
	printf("%s-", get_next_line(fd));
	close (fd);
}
