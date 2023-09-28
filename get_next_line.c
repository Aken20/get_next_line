/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:00:12 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/19 08:14:41 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char *rem_line(char *tmp)
{
	int		i;
	int		c;
	char	*ntmp;

	i = 1;
	c = 0;
	while (tmp[i] != '\n')
		i++;
	ntmp = ft_strdup(tmp + i);
	free(tmp);
	return (ntmp);
}

static	char *set_line(char *tmp)
{
	char	*str;
	int		c;
	int		i;

	c = 0;
	i = 0;
	while (tmp[c] && tmp[i] != '\n')
		i++;
	str = (char *)malloc(sizeof (char) * (i + 1));
	if (tmp[c] && tmp[c] == '\n')
	{
		c++;
		i = 0;
		while (tmp[c] && tmp[c] != '\n')
		{
			str[i++] = tmp[c++];
		}
		str[i] = 0;
		return (str);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*str;
	static char		*tmp = 0;
	int				i;

	i = 1;
	// if (!fd || !read(fd, buf, 0))
	// 	return (0);
	if (tmp != 0)
	{
		while (tmp[i] != '\n')
			i++;
		str = set_line(tmp);
		tmp = rem_line(tmp);
		return (str);
	}
	buf = (char *)malloc(BUFFER_SIZE + 1);
	str = (char *)malloc(BUFFER_SIZE + 1);
	while ((read(fd, buf, BUFFER_SIZE)))
	{
		buf[BUFFER_SIZE + 1] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
		{
			tmp = ft_strchr(str, '\n');
			*tmp = 0;
			tmp = &tmp[1];
			free(buf);
			return (str);
		}
		ft_bzero(buf);
	}
	free(buf);
	return (str);
}

int	main(void)
{
	char	*s;
	int		fd;

	fd = open("./test.txt", O_RDONLY);
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	close (fd);
}
