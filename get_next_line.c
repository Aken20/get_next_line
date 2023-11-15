/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:00:12 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/11/15 05:15:19 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*set_tmp(char *str)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	c = ft_strlen(str) - i;
	tmp = (char *)malloc(sizeof (char) * (c + 1));
	c = 0;
	i += 1;
	while (str[i])
	{
		tmp[c] = str[i];
		i++;
		c++;
	}
	tmp[c] = 0;
	return (tmp);
}

static	char	*first_line(char *str)
{
	int		i;
	char	*nstr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	nstr = (char *)malloc(sizeof (char) * (i + 1));
	if (!nstr)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		nstr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		nstr[i++] = '\n';
	nstr[i] = 0;
	return (nstr);
}

static	char	*rem_line(char *tmp)
{
	int		i;
	int		c;
	char	*ntmp;

	i = 0;
	c = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	i++;
	ntmp = ft_strdup(tmp + i);
	return (ntmp);
}

static	char	*set_line(char *tmp)
{
	char	*str;
	int		c;
	int		i;

	c = 0;
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	str = (char *)malloc(sizeof (char) * (i + 1));
	while (tmp[c] && tmp[c] != '\n')
	{
		str[c] = tmp[c];
		c++;
	}
	str[c] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*str;
	static char		*tmp;

	if (!fd)
		return (0);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	if (tmp)
	{
		if (!ft_strchr(tmp, '\n'))
		{
			while ((read(fd, buf, BUFFER_SIZE)))
			{
				buf[BUFFER_SIZE + 1] = 0;
				str = ft_strjoin(tmp, buf);
			}
		}
		str = set_line(tmp);
		tmp = rem_line(tmp);
		return (str);
	}
	while ((read(fd, buf, BUFFER_SIZE)))
	{
		buf[BUFFER_SIZE + 1] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
		{
			tmp = set_tmp(str);
			str = first_line(str);
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
		printf("%s", s);
	close (fd);
}
