/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 07:16:11 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/11/17 10:08:13 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*first_line(char *str)
{
	int		i;
	int		c;
	char	*new_str;

	i = 0;
	c = 0;
	if (!str)
		return (NULL);
	while (str[c] && str[c] != '\n')
		c++;
	if (str[c] && str[c] == '\n')
		c++;
	new_str = (char *)malloc(sizeof(char) * (c + 1));
	if (!new_str)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_str[i++] = '\n';
	new_str[i] = 0;
	return (new_str);
}

static	char	*set_tmp(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	tmp = ft_strdup(str + i, 0);
	free(str);
	if (!tmp)
		return (NULL);
	return (tmp);
}

static char	*print_line(char *str, char *buf, int fd)
{
	static char	*tmp;
	char		*line;
	int			i;

    i = 1;
	if (tmp && ft_strchr(tmp + 1, '\n'))
	{
		line = first_line(tmp);
		tmp = set_tmp(tmp);
		return (free(buf), line);
	}
	str = ft_strdup(tmp, 1, ft_strlen(str));
	while (i > 0)
	{
        i = read(fd, buf, BUFFER_SIZE);
        if (buf[i])
		    str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
		{
			line = first_line(str);
			tmp = set_tmp(str);
			return (free(buf), line);
		}
		ft_bzero(buf);
	}
	line = first_line(str);
	tmp = set_tmp(str);
	if (str)
		return (free(buf), line);
	return (free(buf), free(tmp), free(str), NULL);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buf = (char *)malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	str = 0;
	return (print_line(str, buf, fd));
}

// int	main(void)
// {
// 	char	*s;
// 	int		fd;
// 	int		i;

// 	i = 1;
// 	fd = open("./test.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	while (s != 0)
// 	{
// 		printf("%d: %s", i, s);
// 		free(s);
// 		s = get_next_line(fd);
// 		i++;
// 	}
// 	free(s);
// 	close (fd);
// }
