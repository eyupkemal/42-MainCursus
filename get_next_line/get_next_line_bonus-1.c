/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:35:18 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/03/09 19:17:30 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		index;
	int		index2;

	index = -1;
	index2 = 0;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1[++index] != '\0')
		s3[index] = s1[index];
	while (s2[index2] != '\0')
		s3[index++] = s2[index2++];
	s3[index] = '\0';
	free(s1);
	return (s3);
}

char	*ft_get_one_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free (left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free (left_str);
	return (str);
}

char	*ft_search_n_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free (buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_search_n_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_one_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return (line);
}
