/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:39:51 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/22 12:59:36 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_buffer(char **sbuffer)
{
	if (sbuffer && *sbuffer)
	{
		free(*sbuffer);
		*sbuffer = NULL;
	}
}

int		print_buffer(char **sbuffer, char **line, char *tmp)
{
	char	*memory;

	free_buffer(line);
	*line = ft_strsub(*sbuffer, 0, ft_strlen(*sbuffer) - ft_strlen(tmp));
	memory = *sbuffer;
	*sbuffer = ft_strsub(*sbuffer, ft_strlen(*line) + 1, ft_strlen(*sbuffer));
	free_buffer(&memory);
	return (1);
}

int		refill_buff(int fd, char **sbuffer, char *tmp, char **line)
{
	char	*free_buf;
	int		rs;
	char	*tmp2;

	while ((rs = read(fd, tmp, BUFFER_SIZE)) != -1)
	{
		if (rs == 0)
			break ;
		tmp[rs] = 0x00;
		free_buf = *sbuffer;
		*sbuffer = ft_strjoin(*sbuffer, (const char *)tmp);
		free_buffer(&free_buf);
		if ((tmp2 = ft_strchr((const char *)(*sbuffer), '\n')))
		{
			return (print_buffer(sbuffer, line, tmp2));
		}
	}
	return (rs);
}

int		get_next_line(int fd, char **line)
{
	static char	*sbuffer[FD_SIZE];
	int			rs;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup("");
	if ((tmp = ft_strchr((const char *)sbuffer[fd], '\n')))
	{
		return (print_buffer(&sbuffer[fd], line, tmp));
	}
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	rs = refill_buff(fd, &sbuffer[fd], tmp, line);
	free(tmp);
	if (rs != 0)
		return (rs);
	if (ft_strlen((const char *)sbuffer[fd]) > 0)
	{
		free_buffer(line);
		*line = ft_strdup((const char*)sbuffer[fd]);
		free_buffer(&sbuffer[fd]);
	}
	return (0);
}
