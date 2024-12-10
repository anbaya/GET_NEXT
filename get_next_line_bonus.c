/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:55:01 by anbaya            #+#    #+#             */
/*   Updated: 2024/12/10 21:15:01 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	freedom(char **new_sv, char **tmp)
{
	free(*new_sv);
	*new_sv = NULL;
	free(*tmp);
	*tmp = NULL;
}

char	*line_taker(char **sv)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	i = 0;
	while ((*sv)[i] != '\n' && (*sv)[i] != '\0')
		i++;
	tmp1 = ft_substr(*sv, 0, i + 1);
	i++;
	tmp2 = ft_substr(*sv, i, (ft_strlen(*sv) - i));
	free(*sv);
	*sv = tmp2;
	return (tmp1);
}

ssize_t	reader(int fd, char **sv, ssize_t buffer_sz)
{
	char	*tmp;
	ssize_t	ret;
	size_t	new_size;
	char	*new_sv;

	tmp = malloc(sizeof(char) * (buffer_sz + 1));
	if (!tmp)
		return (-1);
	ret = read(fd, tmp, buffer_sz);
	if (ret < 0)
		return (free(tmp), ret);
	tmp[ret] = '\0';
	new_size = (ft_strlen(*sv) + ret + 1);
	new_sv = malloc(sizeof(char) * new_size);
	if (!new_sv)
		return (-1);
	ft_strlcpy(new_sv, *sv, ft_strlen(*sv) + 1);
	ft_strlcat(new_sv, tmp, ft_strlen(new_sv) + ft_strlen(tmp) + 1);
	free(*sv);
	*sv = malloc(sizeof(char) * new_size);
	if (!(*sv))
		return (-1);
	ft_strlcpy(*sv, new_sv, new_size + 1);
	freedom(&new_sv, &tmp);
	return (ret);
}

char	*last_line(char **sv)
{
	char	*last;

	last = malloc(ft_strlen(*sv) + 1);
	if (!last)
		return (NULL);
	ft_strlcpy(last, *sv, ft_strlen(*sv) + 1);
	free(*sv);
	*sv = NULL;
	return (last);
}

char	*get_next_line(int fd)
{
	static char	*sv[1024];
	ssize_t		reader_return;

	if (!sv[fd])
	{
		sv[fd] = malloc(1);
		sv[fd][0] = '\0';
	}
	while (1)
	{
		if (ft_strchr(sv[fd], '\n'))
			return (line_taker(&sv[fd]));
		else if (!(ft_strchr(sv[fd], '\n')))
			reader_return = reader(fd, &sv[fd], BUFFER_SIZE);
		if (reader_return <= 0)
		{
			if (reader_return == -1)
				return (free(sv[fd]), NULL);
			if (*sv[fd])
				return (last_line(&sv[fd]));
			break ;
		}
	}
	free(sv[fd]);
	return (NULL);
}
