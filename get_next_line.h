/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:41:30 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/22 08:21:27 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define FD_SIZE OPEN_MAX

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int n);
char	*ft_strdup(const char *src);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
#endif
