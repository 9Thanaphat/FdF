/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttangcha <ttangcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:22:18 by ttangcha          #+#    #+#             */
/*   Updated: 2025/02/21 13:22:21 by ttangcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_join_and_free(char *buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(buffer, read_buffer);
	free(buffer);
	return (temp);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc((ft_strlen(buffer) - i) + 1, sizeof(*buffer));
	if (!new_buffer)
		return (NULL);
	while (buffer[++i])
		new_buffer[j++] = buffer[i];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*read_buffer;
	int		read_byte;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	read_buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!read_buffer)
		return (NULL);
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, read_buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			free(read_buffer);
			return (NULL);
		}
		read_buffer[read_byte] = 0;
		buffer = ft_join_and_free(buffer, read_buffer);
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_update_buffer(buffer);
	return (line);
}
