/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eali <eali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:29:45 by eali              #+#    #+#             */
/*   Updated: 2023/09/05 23:03:24 by eali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_allocate(int fd, char *s);
char	*get_lline(char *s);
char	*rewrite(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_calloc(void);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);

#endif