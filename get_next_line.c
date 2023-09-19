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

char	*get_next_line(int fd)
{
	char			*buf;
	char			*str;
	static char		*tmp = 0;
	int				i;

	i = 0;
	if (!fd || !read(fd, buf, 1))
		return (0);
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (tmp != 0)
	{
		str = ft_strjoin(str, tmp);
		// printf("\n%s\n", tmp);
		tmp = 0;
	}
	buf = (char *)malloc(BUFFER_SIZE + 1);
	while ((read(fd, buf, BUFFER_SIZE)))
	{
		// buf[i + 1] = 0;
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
		printf("%s\n", s);
		free(s);
	}
	close (fd);
}
