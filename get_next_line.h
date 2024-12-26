/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:44:03 by root              #+#    #+#             */
/*   Updated: 2024/10/28 12:49:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_strdup_gnl(const char *s);
void	*ft_memset_gnl(void *s, int c, size_t n);
void	ft_bzero_gnl(void *s, size_t n);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
int		ft_strlen_gnl(const char *s);
char	*get_next_line(int fd);

#endif
