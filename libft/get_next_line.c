/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:50:39 by mabouche          #+#    #+#             */
/*   Updated: 2018/05/21 14:48:58 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				*ft_memmjoin\
	(void const *s1, void const *s2, size_t l1, size_t l2)
{
	size_t	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (l1 + l2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		((char *)str)[i] = ((char *)s1)[i];
		i++;
	}
	while (i < l1 + l2)
	{
		((char *)str)[i] = ((char *)s2)[i - l1];
		i++;
	}
	free((char *)s1);
	free((char *)s2);
	return (str);
}

static int			my_read(int fd, char **str)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	temp = *str;
	*str = ft_strjoin(*str, buf);
	if (*str == NULL)
		*str = ft_strdup(buf);
	if (temp != 0)
		free(temp);
	return (ret);
}

static int			get_line(char **str, char **line)
{
	int		i;
	char	*ptr;

	i = 0;
	if (*str[0] != '\0')
	{
		ptr = ft_strchr(*str, '\n');
		if (ptr == NULL)
			ptr = ft_strchr(*str, '\0');
		while ((*str)[i] != (*ptr))
			i++;
		*line = ft_strsub(*str, 0, i);
		if (*ptr == '\n')
			*str = (char *)ft_memmove(*str, *str + i + 1, ft_strlen(*str) - i);
		else
			ft_strdel(str);
		return (1);
	}
	else
	{
		ft_strdel(str);
		*line = NULL;
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*str[OPEN_MAX];

	ret = 1;
	if (!line || BUFF_SIZE < 1 || fd < 0 || fd > OPEN_MAX)
		return (-1);
	while (!str[fd] || ((!ft_strchr(str[fd], '\n') && ret)))
	{
		ret = my_read(fd, &str[fd]);
		if (ret == -1)
			return (-1);
	}
	return (get_line(&str[fd], line));
}
