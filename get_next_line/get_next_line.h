/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaraogl <ekaraogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:29:40 by ekaraogl          #+#    #+#             */
/*   Updated: 2022/03/09 19:28:23 by ekaraogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4 //okuma sayısı 4 olunca 4 harf okur 
# endif

char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(const char *s);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);

#endif
