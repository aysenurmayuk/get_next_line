/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayuk <amayuk@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:09:09 by amayuk            #+#    #+#             */
/*   Updated: 2024/02/11 17:02:41 by amayuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *buf, char *src)
{
	int		read_len;
	char	*tmp;

	while (1)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len == -1)
			return (NULL);
		else if (read_len == 0)
			break ;
		buf[read_len] = '\0';
		if (src == NULL)
			src = ft_strdup("");
		tmp = src;
		src = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (src);
}

char	*ft_cut(char *line)
{
	int		i;
	char	*dest;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	dest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (dest == NULL)
		return (NULL);
	if (dest[0] == '\0')
	{
		free(dest);
		dest = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*src[10240];
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = ft_read(fd, buf, src[fd]);
	free (buf);
	if (line == NULL)
	{
		free(src[fd]);
		src[fd] = NULL;
		return (NULL);
	}
	src[fd] = ft_cut(line);
	return (line);
}
