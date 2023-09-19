/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:00:12 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/19 05:22:32 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buf;
	char			*str;
	char			*tmp;
	int				i;

	i = 0;
	if (!fd)
		return (0);
	buf = (char *)malloc(BUFFER_SIZE);
	str = (char *)malloc(BUFFER_SIZE);
	while (read(fd, buf, BUFFER_SIZE))
	{
		buf[BUFFER_SIZE] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
		{
			tmp = ft_strchr(str, '\n');
			ft_bzero(tmp);
			free(buf);
			return (str);
		}
		ft_bzero(buf);
	}
	free(buf);
	return (str);
}

// int	main(void)
// {
// 	char	*s;
// 	int		fd;

// 	fd = open("./test.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("%s %i", s, BUFFER_SIZE);
// }
