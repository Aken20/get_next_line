/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:00:19 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/11/22 22:28:04 by ahibrahi         ###   ########.fr       */
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

static	char	*set_tmp(char *str, int k)
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
	if (k == 1)
		free(str);
	if (!tmp)
		return (NULL);
	return (tmp);
}

static char	*print_line(char *str, char *buf, int fd)
{
	static char	*tmp;
	int			i;
	char		*line;

	if (tmp && ft_strchr(tmp + 1, '\n'))
	{
		line = first_line(tmp);
		tmp = set_tmp(tmp, 1);
		return (free(buf), line);
	}
	else if (tmp)
		str = ft_strdup(tmp, 1);
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
		{
			line = first_line(str);
			tmp = set_tmp(str, 1);
			return (free(buf), line);
		}
		ft_bzero(buf);
	}
	line = first_line(str);
	tmp = set_tmp(str, 1);
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
