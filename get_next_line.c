/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:00:19 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/11/20 05:46:36 by aken             ###   ########.fr       */
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
		return (0);
	while (str[c] && str[c] != '\n')
		c++;
	if (str[c] == '\n')
		c++;
	new_str = (char *)malloc(sizeof (char) * (c + 1));
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
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	tmp = ft_strdup(str + i);
	return (tmp);
}

static	char	*print_line(char *str, char *buf, int fd)
{
	static char		*tmp;

	if (tmp != 0 && ft_strchr(tmp + 1, '\n'))
	{
		str = first_line(tmp);
		tmp = set_tmp(tmp);
		return (str);
	}
	else if (tmp != 0 && !ft_strchr(tmp + 1, '\n'))
		str = strdup(tmp);
	while ((read(fd, buf, BUFFER_SIZE)))
	{
		buf[BUFFER_SIZE + 1] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
		{
			tmp = set_tmp(str);
			return (free(buf), first_line(str));
		}
		ft_bzero(buf);
	}
	free(buf);
	tmp = set_tmp(str);
	if (str[0] != '\0')
		return (first_line(str));
	return (free(tmp), 0);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483648)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	str = 0;
	return (print_line(str, buf, fd));
}

/*char	*get_next_line(int fd)
{
	char			*buf;
	char			*str;
	static char		*tmp;
	int				i;

	i = 1;
	if (!fd)
		return (0);
	if (tmp)
	{
		if (ft_strchr(tmp + 1, '\n'))
		{
			str = first_line(tmp);
			tmp = set_tmp(tmp);
			return (str);
		}
		else
			str = strdup(tmp);
	}
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while  ((i = read(fd, buf, BUFFER_SIZE)))
	{
		buf[BUFFER_SIZE + 1] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
		{
			// free(buf);
			tmp = set_tmp(str);
			return (first_line(str));
		}
		ft_bzero(buf);
	}
	free(buf);
	if (tmp != 0)
	{
		tmp = 0;
		return(str);
	}
	return (0);
}*/

int	main(void)
{
	char	*s;
	int		fd;
	int		i;

	i = 1;
	fd = open("./test.txt", O_RDONLY);
	s = get_next_line(fd);
		printf("%d:%s", i, s);
	close (fd);
}
