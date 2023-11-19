/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:00:12 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/11/19 20:58:30 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char    *first_line(char *str)
{
    int     i;
    int     c;
    char    *new_str;

    i = 0;
    c = 0;
    if (!str)
        return (0);
    while(str[c] && str[c] != '\n')
        c++;
    if (str[c] == '\n')
        c++;
    new_str = (char *)malloc(sizeof (char) * (c + 1));
    while(str[i] && str[i] != '\n')
    {
        new_str[i] = str[i];
        i++;
    }
	if (str[i] == '\n')
    	new_str[i++] = '\n';
	new_str[i] = 0;
    return (new_str);
}

static	char    *set_tmp(char *str)
{
    int     i;
    char    *tmp;
    
    i = 0;
    while(str[i] && str[i] != '\n')
        i++;
    if (str[i] && str[i] == '\n')
       i++;
    //if (str[i])
    //{
        tmp = ft_strdup(str + i);
        return (tmp);
    //}
    //return (0);
}

static	char    *print_line(char *str, char *buf, int fd)
{
    static char		*tmp;

    if (tmp && ft_strchr(tmp + 1, '\n'))
        {
            str = first_line(tmp);
            tmp = set_tmp(tmp);
            return (str);
        }
    else if (tmp && !ft_strchr(tmp + 1, '\n'))
        str = strdup(tmp);
	while ((read(fd, buf, BUFFER_SIZE)))
	{
        buf[BUFFER_SIZE + 1] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
		{
			tmp = set_tmp(str);
			return (first_line(str));
		}
		ft_bzero(buf);
    }
    tmp = set_tmp(str);
    return (first_line(tmp));
}

char	*get_next_line(int fd)
{
    char			*buf;
	char			*str;

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
	while ((i = read(fd, buf, BUFFER_SIZE)))
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
    int     i;

    i = 1;
	fd = open("./test.txt", O_RDONLY);
	s = get_next_line(fd);
	while (s != NULL)
	{
    	printf("%d:%s", i, s);
		s = get_next_line(fd);
       i++;
   }
	close (fd);
}
